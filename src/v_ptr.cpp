#include "../include/vector_alloc.h"

// C-compatible functions using `VectorMemory`
extern "C"
{
    void* v_alloc(size_t size)
    {
        try {
            VectorMemory mem(size);
            return mem.get();
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << '\n';
            return nullptr;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << e.what() << '\n';
            return nullptr;
        }
    }

    void v_free(void* ptr)
    {
        VectorPointer::getInstance().deallocate(ptr);
    }
}