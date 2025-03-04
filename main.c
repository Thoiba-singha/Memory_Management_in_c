#include <stdio.h>
#include "include/v_ptr.h"

typedef struct {
    int* id;
    char name[50];
}Student;

typedef union {
    int* salary;
    char* addr;
}Data;

typedef enum {
    RED,
    BLUE,
    GREEN
} Color;

void testScope() {

    // enum example
   /* Color* color = (Color*)gc_alloc(sizeof(Color));
    *color = GREEN;
    printf("Color: %d\n", *color);*/

    // union example
    /*Data* data = (Data*)gc_alloc(sizeof(Data));
    data->salary = (int*)gc_alloc(sizeof(int));
    *(data->salary) = 500;
    printf("salary: %d\n", *(data->salary));

    Data* data = (Data*)gc_alloc(sizeof(Data));
    data->addr = (char*)gc_alloc(sizeof(char));
    snprintf(data->addr, 20, "Agartala");
    printf("Address: %s\n", data->addr);*/


    // Struct example
   /* Student* pr = (Student*)gc_alloc(sizeof(Student));
    pr->id = (int*)gc_alloc(sizeof(int));
    *(pr->id) = 10;
    strcpy(pr->name, "Bishal");
    printf("Student: %d, %s\n", *(pr->id), pr->name);


    // Array example
    int* arr = (int*)gc_alloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }


    // Int example
    int* num = (int*)gc_alloc(sizeof(int));
    *num = 22;
    printf("Int value: %d\n", *num);

    // char example
    char* ch = (char*)gc_alloc(sizeof(char));
    *ch = 'A';
    printf("Value: %c\n", *ch);


    // string example
    char* str = (char*)gc_alloc(sizeof(char));
    strcpy(str, "Hello");
    printf("Value: %s\n", str);

    // unsigned example
    unsigned char* uch = (unsigned char*)gc_alloc(sizeof(unsigned char));
    *uch = 200;
    printf("Value: %u\n", *uch);


    // Float example
    float* num2 = (float*)gc_alloc(sizeof(float));
    *num2 = 3.14f;
    printf("float value: %.2f\n", *num2);*/

    // Int example
    int* num = (int*)gc_alloc(sizeof(int));
    *num = 22;
    printf("Int value: %d\n", *num);

    Student* pr = (Student*)gc_alloc(sizeof(Student));
    pr->id = (int*)gc_alloc(sizeof(int));
    *(pr->id) = 10;
    strcpy(pr->name, "Bishal");
    printf("Student: %d, %s\n", *(pr->id), pr->name);


}
int main() {
    testScope();
    return 0;
}
