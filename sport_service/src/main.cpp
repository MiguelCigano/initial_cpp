#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <atomic>

// external
#include <httplib.h>
#include <nlohmann/json.hpp>

// void send_update_to_widget(const std::string& json_path)
// {
//     bundle* b = bundle_create();
//     bundle_add_str(b, "json_path", json_path.c_str());

//     int ret = message_port_send_message_remote("WIDGET_APP_ID",
//                                                "WIDGET_PORT",
//                                                b);
//     if (ret != MESSAGE_PORT_ERROR_NONE)
//         printf("Error enviando mensaje: %d\n", ret);

//     bundle_free(b);
// }

using json = nlohmann::json;
using namespace std::chrono_literals;
std::atomic<bool> keep_running{true};

static void write_file(const std::string &path, const std::string &content) {
    std::ofstream ofs(path, std::ios::out | std::ios::trunc);
    if (!ofs) {
        std::cerr << "[Fail] - no open path " << path << " to write" << std::endl;
        return;
    }
    ofs << content;
    ofs.close();
    return;
}

bool fetch_url_and_save(const std::string &host_or_url, const std::string &output_path, int timeout_seconds = 10) {
    try {
        // Si la URL empiza con "https://" o "http://", extraemos esquema y el resto
        bool is_https = false;
        std::string url = host_or_url;
        if (url.rfind("https://", 0) == 0) {
            is_https = true;
            url = url.substr(strlen("https://"));
        }
        else if (url.rfind("http://", 0) == 0) {
            url = url.substr(strlen("http://"));
        }
        else {
            // Si no hay nada, se asume http
        }

        // Si el usuario pasa una URL completa con path, separa host y path
        std::string host;
        std::string path = "/";
        auto pos = url.find('/');
        if (pos != std::string::npos) {
            host = url.substr(0, pos);
            path = url.substr(pos);
        }
        else {
            host = url;
            path = "/";
        }

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        // Si compilaste con soporte SSL, usa SSLClient para https
        if (is_https) {
            httplib::SSLClient cli(host.c_str());
            cli.set_connection_timeout(timeout_seconds); // segundos
            auto res = cli.Get(path.c_str());
            if (!res) {
                std::cerr << "HTTP error (no response) al pedir " << host << path << "\n";
                return false;
            }
            if (res->status != 200) {
                std::cerr << "HTTP status " << res->status << " al pedir " << host << path << "\n";
                return false;
            }
            write_file(output_path, res->body);
            return true;
        } else {
            httplib::Client cli(host.c_str());
            cli.set_connection_timeout(timeout_seconds);
            auto res = cli.Get(path.c_str());
            if (!res) {
                std::cerr << "HTTP error (no response) al pedir " << host << path << "\n";
                return false;
            }
            if (res->status != 200) {
                std::cerr << "HTTP status " << res->status << " al pedir " << host << path << "\n";
                return false;
            }
            write_file(output_path, res->body);
            return true;
        }
#else
        // Sin SSL support, solo http
        if (is_https) {
            std::cerr << "Error: esta build no tiene soporte SSL (https). Reconfigura CMake con -DUSE_SSL=ON\n";
            return false;
        }
        httplib::Client cli(host.c_str());
        cli.set_connection_timeout(timeout_seconds);
        auto res = cli.Get(path.c_str());
        if (!res) {
            std::cerr << "HTTP error (no response) al pedir " << host << path << "\n";
            return false;
        }
        if (res->status != 200) {
            std::cerr << "HTTP status " << res->status << " al pedir " << host << path << "\n";
            return false;
        }
        write_file(output_path, res->body);
        return true;
#endif

    } catch (const std::exception &e) {
        std::cerr << "Excepción en fetch_url_and_save: " << e.what() << "\n";
        return false;
    }
}

void periodic_worker(const std::string url, const std::string output_path, int interval_seconds) {
    std::cout << "Run each " << interval_seconds << std::endl;
    while (keep_running.load()) {
        bool ok = fetch_url_and_save(url, output_path, 15);
        if (ok) {
            // intento de parsear y mostrar resumen breve
            try {
                std::ifstream ifs(output_path);
                json j;
                ifs >> j;
                std::cout << "[Save] " << output_path << " (" << j.dump(0).size() << " bytes)" << std::endl;

                // Si la respuesta tiene "events" (TheSportsDB), mostramos resumen
                if (j.contains("events")) {
                    auto events = j["events"];
                    std::cout << "Eventos encontrados: " << events.size() << "\n";
                    for (size_t i = 0; i < std::min<size_t>(10, events.size()); ++i) {
                        std::string home = events[i].value("strHomeTeam", "N/A");
                        std::string away = events[i].value("strAwayTeam", "N/A");

                        // Manejo seguro de marcadores que pueden ser null o int
                        std::string scoreHome = events[i]["intHomeScore"].is_null() ? "-" : std::to_string(events[i]["intHomeScore"].get<int>());
                        std::string scoreAway = events[i]["intAwayScore"].is_null() ? "-" : std::to_string(events[i]["intAwayScore"].get<int>());
                        std::string date = events[i].value("dateEvent", "N/A");
                        std::string time = events[i].value("strTime", "N/A");

                        std::cout << "  - " << home << " " << scoreHome
                        << " vs " << away << " " << scoreAway
                        << " (" << date << " " << time << ")\n";
                    }
                } else {
                    std::cout << "Respuesta no contiene 'events'. Revisa el JSON guardado.\n";
                }
            } catch (const std::exception &e) {
                std::cerr << "No pude parsear JSON guardado: " << e.what() << "\n";
            }
        } else {
            std::cerr << "Falló la obtención de datos en este ciclo.\n";
        }

        for (int s = 0; s < interval_seconds && keep_running.load(); ++s) {
            std::this_thread::sleep_for(1s);
        }
    }
    std::cout << "Worker detenido.\n";
}

int main(int argc, char** argv) {
    // Valores por defecto:
    // std::string url = "https://www.thesportsdb.com/api/v1/json/3/eventsnext.php?id=133604"; // next events
    // std::string url = "https://www.thesportsdb.com/api/v1/json/3/eventslast.php?id=133604"; // last events
    std::string url = "https://www.thesportsdb.com/api/v1/json/3/eventsround.php?id=4328&r=12&s=2025-2026";
 

    std::string output_path = "data.json";
    int interval_seconds = 60; // cada 60s

    if (argc > 1) url = argv[1];
    if (argc > 2) output_path = argv[2];
    if (argc > 3) interval_seconds = std::stoi(argv[3]);

    std::thread t(periodic_worker, url, output_path, interval_seconds);

    std::cout << "Presiona ENTER para terminar...\n";
    std::string dummy;
    std::getline(std::cin, dummy);

    keep_running.store(false);
    t.join();

    std::cout << "Terminando.\n";
    return 0;
}