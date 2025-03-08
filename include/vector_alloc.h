#ifndef VECTOR_ALLOC_H
#define VECTOR_ALLOC_H

#include <unordered_set>
#include <mutex>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "v_ptr.h"

class VectorPointer
{
private:
    std::unordered_set<void*> allocatedMemory;
    std::mutex gcMutex;

    VectorPointer() = default;                     // Private constructor for Singleton
    ~VectorPointer();                              // Destructor to clean up memory

public:
    static VectorPointer& getInstance();           // Singleton instance

    void* allocate(size_t size);                      // Allocates memory and tracks it
    void deallocate(void* ptr);                       // Deallocates memory if tracked
};

class VectorMemory
{
private:
    void* ptr;

public:
    explicit VectorMemory(size_t size);
    ~VectorMemory();

    VectorMemory(const VectorMemory&) = delete;            // Prevent copy
    VectorMemory& operator=(const VectorMemory&) = delete; // Prevent assignment

    void* get() const;
    template <typename T>
    T* getAs() const { return static_cast<T*>(ptr); }
};

#endif // VECTOR_ALLOC_H