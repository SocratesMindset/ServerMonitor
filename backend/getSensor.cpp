// getSensor.cpp
// Обход /sys/class/hwmon и чтение температурных датчиков
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

struct hardwareInfo {
  std::string driverName;
  std::string chip;
  int channel;
  std::string value;
  std::string type;
};

std::vector<hardwareInfo> getSensor() {
  std::vector<hardwareInfo> avalanche = {};
  using namespace std::filesystem;
  directory_iterator monFolder("/sys/class/hwmon/");
  std::regex pattern(R"(temp([0-9]+)_(input|label))");
  for (const directory_entry& currentFile : monFolder) {
    std::filesystem::path driverFile = currentFile.path() / "name";
    std::ifstream driver(driverFile);
    if (!driver.is_open()) {
      std::cerr << "Не удалось открыть driver file" << std::endl;
    }
    std::string dname;
    std::getline(driver, dname);
    std::string filename = currentFile.path().filename().string();
    directory_iterator curMonFolder(currentFile.path());
    for (const directory_entry& currentMonFile : curMonFolder) {
      std::string filenameMon = currentMonFile.path().filename().string();
      std::smatch match;
      if (std::regex_match(filenameMon, match, pattern)) {
        std::string matched = match[1].str();
        std::ifstream sensor(currentMonFile.path());
        if (!sensor.is_open()) {
          std::cerr << "Не удалось открыть sensor file" << std::endl;
        }
        std::string content;
        std::getline(sensor, content);
        hardwareInfo temp = {dname, filename, std::stoi(match[1].str()),
                             content, match[2].str()};
        avalanche.push_back(temp);
        sensor.close();
      }
    }
    driver.close();
  }
  return avalanche;
}
