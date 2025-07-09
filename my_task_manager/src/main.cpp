#include "httplib.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int main(int argc, char** argv) {

    httplib::Server svr;
    // Path root
    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Open svr using C++", "text/plain");
    });

    // Get all tasks
    svr.Get("/tasks", [](const httplib::Request& req, httplib::Response& res) {
        std::ifstream file("../data/tasks.json");

        if (!file.is_open()) {
            res.status = 500;
            res.set_content("Open ERROR tasks.json", "text/plain");
            return;
        }

        json tasks;
        file >> tasks;
        res.set_content(tasks.dump(4), "application/json");
    });

    // Add new task
    svr.Post("/tasks", [](const httplib::Request& req, httplib::Response& res) {
        json new_task;
        try {
            new_task = json::parse(req.body);
        } 
        catch (const std::exception& e) {
            res.status = 400;
            res.set_content("JSON invalid", "text/plain");
            return;
        }

        std::ifstream in_file("../data/tasks.json");
        json tasks = json::array();
        if (in_file.is_open()) {
            in_file >> tasks;
            in_file.close();
        }

        int max_id = 0;
        for (const auto& task : tasks) {
            if (task.contains("id") && task["id"].is_number()) {
                max_id = std::max(max_id, task["id"].get<int>());
            }
        }

        new_task["id"] = max_id + 1;
        tasks.push_back(new_task);

        std::ofstream out_file("../data/tasks.json");
        out_file << tasks.dump(4);
        out_file.close();

        res.status = 201;
        res.set_content(new_task.dump(4), "application/json");

    });

    std::cout << "Svr listening on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}