#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Newspaper {
    public:
        std::string title;
        std::vector<std::string> entries;

        Newspaper(const std::string &title) : title(title) {}
        void add_entry(const std::string& entry) {
            static int count = 1;
            entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
        }

        void save(const std::string& filename) {
            std::ofstream ofs(filename);
            for (auto& e : entries) {
                ofs << e << std::endl;
            }
        }
};

class PersistenceManager
{
    public:
        static void save(const Newspaper& news, const std::string& filename) {
            std::ofstream ofs(filename);
            for (auto& e : news.entries) {
                ofs << e << std::endl;
            }
        }

        static void save_as_json(const Newspaper& news, const std::string& filename) {
            json j_obj;
            j_obj["title"] = news.title;
            j_obj["entries"] = news.entries;

            std::ofstream ofs(filename);
            ofs << j_obj.dump(4); // print spaces
        }
};

int main (int argc, char **argv) {
    Newspaper news{"Time"};
    news.add_entry("Sports");
    news.add_entry("Red note");
    news.add_entry("Social");

    PersistenceManager perManager;
    perManager.save(news, "diario_text.txt");
    perManager.save_as_json(news, "diario.json");

    std::cout << "Done!" << std::endl;
    // getchar();

    return 0;
}

