#ifndef V_PTR_H
#define V_PTR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

    void* v_alloc(size_t size);
    void v_free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif // V_PTR_H