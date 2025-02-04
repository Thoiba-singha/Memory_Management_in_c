#ifndef V_MEMORY_H
#define V_MEMORY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Cleanup function for automatic memory deallocation
void cleanup(void *ptr);

// Macro for automatic deallocation
#define vector_ptr(type) type* __attribute__((cleanup(cleanup)))

#endif // V_MEMORY_H
