#pragma once

#ifdef COMPILING_ENGINE
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

ENGINE_API int add_numbers(int a, int b);
