#include "include/v_memory.h"

// Define a struct with automatic memory management
struct Employee {
    int id;
    vector_ptr(char) name;  // Automatically managed string
};

int main() {
    // Example 1: Allocate memory for an int
    vector_ptr(int) num1 = malloc(sizeof(int));
    *num1 = 42;

    // Example 2: for float
    vector_ptr(float) num2 = malloc(sizeof(float));
    *num2 = 3.14f;

    // Example 3: for double
    vector_ptr(double) num3 = malloc(sizeof(double));
    *num3 = 3.14456;

    // Example 4: for long long
    vector_ptr(long long) num4 = malloc(sizeof(long long));
    *num4 = 123456789012345LL;

    // Example 5: for unsigned int
    vector_ptr(unsigned int) num5 = malloc(sizeof(unsigned int));
    *num5 = 4294967295U;

    // Example 6: for char
    vector_ptr(char) character = malloc(sizeof(char));
    *character = 'A';

    // Example 7: Allocate memory for a string
    vector_ptr(char) str = malloc(20 * sizeof(char));
    strcpy(str, "Hello, World!");

    // Example 8: Allocate memory for an array of integers
    vector_ptr(int) arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Example 9: Allocate memory for a struct
    vector_ptr(struct Employee) myStruct = malloc(sizeof(struct Employee));
    myStruct->id = 10;
    myStruct->name = malloc(20 * sizeof(char));
    strcpy(myStruct->name, "John Doe");

    // Print allocated values
    printf("int = %d\n", *num1);
    printf("float = %.2f\n", *num2);
    printf("double = %.5lf\n", *num3);
    printf("long long = %lld\n", *num4);
    printf("Unsigned int = %u\n", *num5);

    printf("char = %c\n", *character);
    printf("string = %s\n", str);
    printf("arr = ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("id = %d, name = %s\n", myStruct->id, myStruct->name);

    return 0;
}
