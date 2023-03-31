#pragma once
#if _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#ifdef _WIN32
extern "C"{
DLL_EXPORT int getpid();
DLL_EXPORT bool exist_pid(int pid);
DLL_EXPORT bool exist_pid_with_title(int pid,const char* title);
DLL_EXPORT int show_window(int pid,const char* title);
}
#endif