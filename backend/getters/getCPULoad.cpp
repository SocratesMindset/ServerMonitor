// getCPULoad.cpp
// Получение значений нагрузки центрального процессора и количества ядер
// центрального процессора (потоков если быть максимально точным) из виртуальной
// файловой системы /proc/loadavg
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

std::vector<float> getCPULoad() {
  unsigned int coreCount = std::thread::hardware_concurrency();
  float formattedCore = static_cast<float>(coreCount);
  std::ifstream file("/proc/loadavg");
  if (!file.is_open()) {
    std::cerr << "Не удалось открыть /proc/loadavg" << std::endl;
    return {};
  }
  std::vector<float> load = {};
  float load1, load5, load15;
  if (file >> load1 >> load5 >> load15) {
    load.push_back(load1);
    load.push_back(load5);
    load.push_back(load15);
    load.push_back(formattedCore);
  } else {
    std::cerr << "Ошибка чтения данных" << std::endl;
  }

  file.close();
  return load;
}
