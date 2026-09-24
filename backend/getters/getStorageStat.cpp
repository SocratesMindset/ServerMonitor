// getStorageStat.cpp
// Получение значений дискового пространства
// параметр доступной пользователю памяти не используется в силу недостоверности
// итоговых значений (подробнее см. о том что такое свободная память на
// unix-подобных системах)
#include <sys/statvfs.h>

struct Storage {
  unsigned long long total;
  unsigned long long free;
  unsigned long long used;
};

Storage getStorageStat() {
  struct statvfs stat;
  statvfs("/", &stat);
  const long int gb = 1024 * 1024 * 1024;
  unsigned long long total = stat.f_blocks * stat.f_frsize;
  unsigned long long free = stat.f_bavail * stat.f_frsize;
  unsigned long long used = total - free;
  Storage tuple = {total / gb, free / gb, used / gb};
  return tuple;
}
