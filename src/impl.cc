#ifdef _WIN32
#include <windows.h>
#endif
#include "pub.h"


#ifdef _WIN32
HWND find_window(int pid, const char* title)
{
   HWND hWnd = nullptr;
   do {
      hWnd                 = FindWindowEx(nullptr, hWnd, nullptr, title);
      DWORD dwWndProcessId = 0;
      GetWindowThreadProcessId(hWnd, &dwWndProcessId);
      if (dwWndProcessId == pid) { return hWnd; }
   } while (hWnd != nullptr);
   return nullptr;
}


extern "C"
{
   DLL_EXPORT int getpid() { return GetCurrentProcessId(); }

   DLL_EXPORT bool exist_pid(int pid)
   {
      const HANDLE hd =
        OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
      if (hd == nullptr) { return false; }
      CloseHandle(hd);
      return true;
   }

   DLL_EXPORT int show_window(int pid, const char* title)
   {
      auto* fd = find_window(pid, title);
      if (fd)
      {
         ShowWindow(fd, SW_RESTORE);
         SetForegroundWindow(fd);
         UpdateWindow(fd);
         return 0;
      }
      return -1;
   }

   DLL_EXPORT bool exist_pid_with_title(int pid, const char* title)
   {
      if (exist_pid(pid)) { return find_window(pid, title) != nullptr; }
      return false;
   }
}
#endif