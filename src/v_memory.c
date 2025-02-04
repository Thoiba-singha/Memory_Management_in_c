#include "../include/v_memory.h"

void cleanup(void *ptr) {
    if (*(void **)ptr != NULL) {
        free(*(void **)ptr);
        *(void**)ptr = NULL;
        printf("Memory freed\n");
    }
}
