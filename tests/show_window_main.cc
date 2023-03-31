#include <pub.h>

#include <iostream>
#include <string>
#include <cstring>

#ifdef _WIN32
int main(int argc, char** argv)
{
   if (argc != 3) { return argc; }
   size_t len = strlen(argv[1]);
   char*  end;
   int    pid = std::strtol(argv[1], &end, 10);
   if (argv[1] + len != end)
   {
      std::cerr << "parse pid error!";
      return -1;
   }
   return show_window(pid, argv[2]);
}
#endif