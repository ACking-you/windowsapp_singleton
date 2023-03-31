#include <doctest/doctest.h>
#ifdef _WIN32
#include <windows.h>

#include "pub.h"

TEST_CASE("test pid") {
   const int pid = 18292;
   const char* title = "Note with cards";
   CHECK_EQ( show_window(pid,title),0);
   CHECK_EQ(exist_pid_with_title(pid,title),true);
}
#endif
