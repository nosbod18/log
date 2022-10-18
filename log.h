#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifndef LOG_LEVEL
    #define LOG_LEVEL LOG_INFO
#endif

enum {
    LOG_LEVEL_ALL,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE
};

#if LOG_LEVEL <= LOG_TRACE
    #define trace(...) do {\
        fprintf(stderr, "[%16s:%04d] \033[36m[TRACE]: ", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\033[0m\n");\
    } while (0)
#else
    #define trace(...)
#endif

#if LOG_LEVEL <= LOG_DEBUG
    #define debug(...) do {\
        fprintf(stderr, "[%16s:%04d] [DEBUG]: ", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\n");\
    } while (0)
#else
    #define debug(...)
#endif

#if LOG_LEVEL <= LOG_INFO
    #define info(...) do {\
        fprintf(stderr, "[%16s:%04d] \033[32m[INFO ]: ", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\033[0m\n");\
    } while (0)
#else
    #define info(...)
#endif

#if LOG_LEVEL <= LOG_WARN
    #define warn(...) do {\
        fprintf(stderr, "[%16s:%04d] \033[33m[WARN ]: ", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\033[0m\n");\
    } while (0)
#else
    #define warn(...)
#endif

#if LOG_LEVEL <= LOG_ERROR
    #define error(...) do {\
        fprintf(stderr, "[%16s:%04d] \033[31;1m[ERROR]: ", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\033[0m\n");\
    } while (0)
#else
    #define error(...)
#endif

#if LOG_LEVEL <= LOG_FATAL
    #define fatal(...) do {\
        fprintf(stderr, "[%16s:%04d] \033[35;1m[FATAL]: ", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(stderr, "\033[0m\n");\
        abort();\
    } while (0)
#else
    #define fatal(...)
#endif