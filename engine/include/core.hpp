#pragma once

#ifdef _WIN32
#ifdef COMPILING_ENGINE
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

ENGINE_API void poll_events();