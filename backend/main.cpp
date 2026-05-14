#define CROW_MAIN
#include "crow_all.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/test")
    ([]() {
        crow::response res;
        res.body = "{\"status\": \"ok\"}";
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Content-Type", "application/json");
        return res;
    });

    app.port(8080).multithreaded().run();
}
