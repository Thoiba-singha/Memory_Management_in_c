# VAlloc: Custom Memory Allocator in C++ for C language 

## Overview
VAlloc is a scalable memory allocator mechanism implemented in C++ that ensures automatic memory management. It provides a singleton-based custom class for tracking dynamically allocated memory and a `VectorMemory` class for scoped memory management. Additionally, `v_alloc` and `v_free` functions offer a C-compatible interface for allocation and deallocation.

## Features
- **Automatic Memory Tracking:** The `VectorPointer` singleton manages allocated memory to ensure proper deallocation.
- **Scoped Memory Management:** `VectorMemory` ensures memory is freed when it goes out of scope.
- **C-Compatible Interface:** `v_alloc` and `v_free` allow seamless integration with C code.
- **Thread-Safe Operations:** Uses `std::mutex` to manage concurrent memory allocations and deallocations.


## Installation & Compilation
### Using `g++` || `MSVC` || `Clang`
```sh
g++ -o main main.c src/v_alloc.cpp src/v_ptr.cpp -I include -lpthread
```

### Using `make` || `CMake`
1. Create a `CMakeLists.txt` (if not provided)
2. Run:
```sh
mkdir build
cd build
cmake ..
make
./valloc
```

## Usage
### Allocating Memory
```c
int* num = (int*)gc_alloc(sizeof(int));
*num = 22;
printf("Int value: %d\n", *num);
```

### Struct and Nested Allocation
```c
Student* pr = (Student*)gc_alloc(sizeof(Student));
pr->id = (int*)gc_alloc(sizeof(int));
*(pr->id) = 10;
strcpy(pr->name, "Vector");
printf("Student: %d, %s\n", *(pr->id), pr->name);
```


## Limitations
- Currently it does not support advanced techniques like ownership transfer with copy assignment error.


## Future Improvements
- Implement a more sophisticated strategy (e.g., reference counting, ownership transfer).
- Improve thread safety and performance.
- Add debugging tools for memory tracking.


