

// #include "v_ptr.h"
#include "../include/v_alloc.h"

// C-compatible functions using `ScopedMemory`
extern "C"
{
    void* gc_alloc(size_t size)
    {
        // ? Fix: ScopedMemory is stack-allocated, ensuring auto-cleanup
        ScopedMemory mem(size);
        return mem.get();
    }

    void gc_free(void* ptr)
    {
        GarbageCollector::getInstance().deallocate(ptr);
    }
}