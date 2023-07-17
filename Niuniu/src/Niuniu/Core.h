#pragma once

#ifdef NN_PLATFORM_WINDOWS
#ifdef NN_BUILD_DLL
#define NN_API __declspec(dllexport)
#else
#define NN_API __declspec(dllimport)
#endif // NN_BUILD_DLL
#else
#error Niuniu only support windows!
#endif // NN_PLATFORM_WINDOWS

#define BIT(x) (1<<x)