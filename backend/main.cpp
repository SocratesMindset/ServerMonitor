#define CROW_MAIN
#include "crow_all.h"
#include "getCPULoad.cpp"
#include "getSensor.cpp"

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/api/payload")
  ([]() {
    crow::response res;
    crow::json::wvalue json_response;
    std::vector<float> load = getCPULoad();
    json_response["load1"] = load[0];
    json_response["load5"] = load[1];
    json_response["load15"] = load[2];
    json_response["cores"] = load[3];
    res.body = json_response.dump();
    res.add_header("Access-Control-Allow-Origin", "*");
    res.add_header("Content-Type", "application/json");
    return res;
  });
  CROW_ROUTE(app, "/api/sensor")
  ([]() {
    crow::response res;
    crow::json::wvalue json_response;
    std::vector<hardwareInfo> sensors = getSensor();
    for (int i = 0; i < sensors.size(); i++) {
      json_response[i]["driverName"] = sensors[i].driverName;
      json_response[i]["chip"] = sensors[i].chip;
      json_response[i]["channel"] = sensors[i].channel;
      json_response[i]["value"] = sensors[i].value;
      json_response[i]["type"] = sensors[i].type;
    }
    res.body = json_response.dump();
    res.add_header("Access-Control-Allow-Origin", "*");
    res.add_header("Content-Type", "application/json");
    return res;
  });

  app.port(8080).multithreaded().run();
}
