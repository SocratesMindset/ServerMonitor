#include <iostream>
#include <sys/statvfs.h>

struct Response
{
   unsigned long long total;
   unsigned long long free;
   unsigned long long used;
}

Response getMemoryStat()
{
struct statvfs stat;
statvfs("/", &stat);
const long float= 1024.0 * 1024 * 1024;
unsigned long long total = stat.f_blocks * stat.f_frsize;
unsigned long long free = stat.f_bavail * stat.f_frsize;
unsigned long long used = total - free;
Response tuple={total,free,used};
}




