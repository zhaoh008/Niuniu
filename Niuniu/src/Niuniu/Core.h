﻿#pragma once

#ifdef NN_PLATFORM_WINDOWS
#ifdef NN_BUILD_DLL
#define NN_API __declspec(dllexport)
#else
#define NN_API __declspec(dllimport)
#endif // NN_BUILD_DLL
#else
#error Niuniu only support windows!
#endif // NN_PLATFORM_WINDOWS

#ifdef NN_ENABLE_ASSERTS
#define NN_ASSERT(x, ...) { if(!(x)) { NN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define NN_CORE_ASSERT(x, ...) { if(!(x)) { NN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define NN_ASSERT(x, ...)
#define NN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)