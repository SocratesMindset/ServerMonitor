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
    CROW_ROUTE(app, "/api/temperature")
    ([]() {
        crow::response res;
        crow::json::wvalue json_response;//Можно было и ручками собирать json но crow вот такой удобный функционал предоставляет для сборки json ответа
        int temperature = 34;
        json_response["temperature"] = temperature;
        res.body=json_response.dump();
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Content-Type", "application/json");
        return res;
    });

    app.port(8080).multithreaded().run();
}
