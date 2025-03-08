#include "../include/vector_alloc.h"
#include <iostream>

VectorPointer::~VectorPointer()
{
    std::lock_guard<std::mutex> lock(gcMutex);
    for (void* ptr : allocatedMemory)
    {
        free(ptr);
		ptr = nullptr;
    }
    allocatedMemory.clear();
}

VectorPointer& VectorPointer::getInstance()
{
    static VectorPointer instance;
    return instance;
}

void* VectorPointer::allocate(size_t size)
{
    if (size == 0) {
        throw std::invalid_argument("Allocation size must be greater than 0");
    }

    void* ptr = malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }

    std::lock_guard<std::mutex> lock(gcMutex);
    allocatedMemory.insert(ptr);
    return ptr;
}

void VectorPointer::deallocate(void* ptr)
{
    if (!ptr) {
        return;
    }

    std::lock_guard<std::mutex> lock(gcMutex);
    auto it = allocatedMemory.find(ptr);
    if (it != allocatedMemory.end())
    {
        free(ptr);
        allocatedMemory.erase(it);
    }
    else {
        std::cerr << "Warning: Attempted to deallocate untracked memory\n";
    }
}

// VectorMemory Implementation
VectorMemory::VectorMemory(size_t size)
{
    ptr = VectorPointer::getInstance().allocate(size);
}

VectorMemory::~VectorMemory()
{
    VectorPointer::getInstance().deallocate(ptr);
}

void* VectorMemory::get() const
{
    return ptr;
}