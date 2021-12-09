#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "And64InlineHook.h"

int64_t(*Org_fopen)(const char* path, const char* mode);
int64_t hook_fopen(const char* path, const char* mode)
{
    LOG("fopen path - %s", path); 
    return Org_fopen(path, mode);
}

void* thread_main(void* arg)
{
    // this is a sample
    A64HookFunction((void*)fopen, (void*)hook_fopen, (void**)&Org_fopen);
  
    // If you remove the following, the app may be terminated after executing the code.
    while (true)
    {

    }
}

void __attribute__((constructor)) library_init()
{
    pthread_t threads;
    pthread_create(&threads, NULL, &thread_main, NULL);
}
