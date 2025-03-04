#include "../include/v_alloc.h"
#include <iostream>

GarbageCollector::~GarbageCollector()
{
    std::lock_guard<std::mutex> lock(gcMutex);
    for (void* ptr : allocatedMemory)
    {
        free(ptr);
    }
    allocatedMemory.clear();
}

GarbageCollector& GarbageCollector::getInstance()
{
    static GarbageCollector instance;
    return instance;
}

void* GarbageCollector::allocate(size_t size)
{
    void* ptr = malloc(size);
    if (!ptr)
        throw std::bad_alloc();

    std::lock_guard<std::mutex> lock(gcMutex);
    allocatedMemory.insert(ptr);
    return ptr;
}

void GarbageCollector::deallocate(void* ptr)
{
    if (!ptr)
        return;

    std::lock_guard<std::mutex> lock(gcMutex);
    auto it = allocatedMemory.find(ptr);
    if (it != allocatedMemory.end())
    {
        free(ptr);
        allocatedMemory.erase(it);
    }
}

// ScopedMemory Implementation
ScopedMemory::ScopedMemory(size_t size)
{
    ptr = GarbageCollector::getInstance().allocate(size);
}

ScopedMemory::~ScopedMemory()
{
    GarbageCollector::getInstance().deallocate(ptr);
}

void* ScopedMemory::get() const
{
    return ptr;
}
