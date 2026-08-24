#define CROW_MAIN
#include "crow_all.h"
#include "getSensor.cpp"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/payload")//todo ручка должна будет отдавать нагрузку на компоненты
    ([]() {
        crow::response res;
        res.body = "{\"status\": \"ok\"}";
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Content-Type", "application/json");
        return res;
    });
    CROW_ROUTE(app, "/api/sensor")//готовая ручка - отдала датчики, их значения и названия
    ([]() {
        crow::response res;
        crow::json::wvalue json_response;
        std::vector<hardwareInfo> sensors = getSensor();
        for (int i=0;i<sensors.size();i++)
        {
            json_response[i]["driverName"]=sensors[i].driverName;
            json_response[i]["chip"]=sensors[i].chip;
            json_response[i]["channel"]=sensors[i].channel;
            json_response[i]["value"]=sensors[i].value;
            json_response[i]["type"]=sensors[i].type;
        }
        res.body=json_response.dump();
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Content-Type", "application/json");
        return res;
    });

    app.port(8080).multithreaded().run();
}
