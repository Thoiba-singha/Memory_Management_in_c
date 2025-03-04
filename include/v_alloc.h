#ifndef V_ALLOC_H
#define V_ALLOC_H

#include <unordered_set>
#include <mutex>
#include <cstdlib>
#include <stdexcept>
#include "v_ptr.h"

class GarbageCollector
{
private:
    std::unordered_set<void*> allocatedMemory;
    std::mutex gcMutex;

    GarbageCollector() = default;                     // Private constructor for Singleton
    ~GarbageCollector();                              // Destructor to clean up memory

public:
    static GarbageCollector& getInstance();           // Singleton instance

    void* allocate(size_t size);                      // Allocates memory and tracks it
    void deallocate(void* ptr);                       // Deallocates memory if tracked
};

class ScopedMemory
{
private:
    void* ptr;

public:
    explicit ScopedMemory(size_t size);
    ~ScopedMemory();

    ScopedMemory(const ScopedMemory&) = delete;            // Prevent copy
    ScopedMemory& operator=(const ScopedMemory&) = delete; // Prevent assignment

    void* get() const;
    template <typename T>
    T* getAs() const { return static_cast<T*>(ptr); }
};


#endif // V_ALLOC_H
