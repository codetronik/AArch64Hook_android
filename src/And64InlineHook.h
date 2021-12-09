#pragma once
#include <android/log.h>
#define LOGE(...)   ((void)__android_log_print(ANDROID_LOG_ERROR, "HOOK", __VA_ARGS__))
#define LOG(...)    ((void)__android_log_print(ANDROID_LOG_INFO, "HOOK", __VA_ARGS__))

void A64HookFunction(void* const symbol, void* const replace, void** result);
