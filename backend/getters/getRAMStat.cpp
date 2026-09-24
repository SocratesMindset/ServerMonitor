// getRAMstat.cpp
// Получение значений загрузки оперативной памяти из виртуальной
// файловой системы /proc/meminfo
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

struct Mem {
  std::string key;
  std::string value;
  std::string unit;
};

std::vector<Mem> getRAMStat() {
  std::ifstream file("/proc/meminfo");
  if (!file.is_open()) {
    std::cerr << "Не удалось открыть /proc/mem" << std::endl;
    return {};
  }
  std::regex pattern(R"(([A-Za-z0-9]+)\s*:\s*([0-9]+)\s*([a-zA-Z]+))");
  std::vector<Mem> tuple = {};
  std::string line;
  while (getline(file, line)) {
    std::smatch match;
    if (std::regex_match(line, match, pattern)) {
      std::string matched = match[1].str();
      if (matched == "MemTotal" || matched == "MemAvailable" ||
          matched == "SwapTotal" || matched == "SwapFree") {
        std::string value = match[2].str();
        std::string unit = match[3].str();
        Mem temporary = {matched, value, unit};
        tuple.push_back(temporary);
      }
    }
  }
  file.close();
  return tuple;
}
