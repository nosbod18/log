#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LOG_LEVEL
    #define LOG_LEVEL LOG_LEVEL_DEFAULT
#endif

enum {
    LOG_LEVEL_TRACE     = 0x01,
    LOG_LEVEL_DEBUG     = 0x02,
    LOG_LEVEL_INFO      = 0x04,
    LOG_LEVEL_WARN      = 0x08,
    LOG_LEVEL_ERROR     = 0x10,
    LOG_LEVEL_FATAL     = 0x20,

    LOG_LEVEL_SILENT    = 0x00,
    LOG_LEVEL_DEFAULT   = LOG_LEVEL_INFO | LOG_LEVEL_WARN | LOG_LEVEL_ERROR | LOG_LEVEL_FATAL,
    LOG_LEVEL_ALL       = 0xFF
};

#define LOG(color, tag, ...) do {\
    time_t t___ = time(NULL);\
    struct tm *tm___ = localtime(&t___);\
    char now___[64] = {0};\
    strftime(now___, sizeof now___, "%b %e %T", tm___);\
    fprintf(stderr, "%s%c %s@%s:%d ", color, tag, __func__, __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\033[0m\n");\
} while (0)

#if (LOG_LEVEL & LOG_LEVEL_FATAL) == LOG_LEVEL_FATAL
    #define LOG_FATAL(...)  do { LOG("\033[41m", 'F', __VA_ARGS__); abort(); } while (0)
#else
    #define LOG_FATAL(...)
#endif

#if (LOG_LEVEL & LOG_LEVEL_ERROR) == LOG_LEVEL_ERROR
    #define LOG_ERROR(...) LOG("\033[31m", 'E', __VA_ARGS__)
#else
    #define LOG_ERROR(...)
#endif

#if (LOG_LEVEL & LOG_LEVEL_WARN) == LOG_LEVEL_WARN
    #define LOG_WARN(...)  LOG("\033[33m", 'W', __VA_ARGS__)
#else
    #define LOG_WARN(...)
#endif

#if (LOG_LEVEL & LOG_LEVEL_INFO) == LOG_LEVEL_INFO
    #define LOG_INFO(...)  LOG("\033[32m", 'I', __VA_ARGS__)
#else
    #define LOG_INFO(...)
#endif

#if (LOG_LEVEL & LOG_LEVEL_DEBUG) == LOG_LEVEL_DEBUG
    #define LOG_DEBUG(...) LOG("\033[36m", 'D', __VA_ARGS__)
#else
    #define LOG_DEBUG(...)
#endif

#if (LOG_LEVEL & LOG_LEVEL_TRACE) == LOG_LEVEL_TRACE
    #define LOG_TRACE(...) LOG("\033[35m", 'T', __VA_ARGS__)
#else
    #define LOG_TRACE(...)
#endif
