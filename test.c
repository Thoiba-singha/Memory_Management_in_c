#include <stdio.h>
#include <string.h>
#include "include/v_ptr.h"

typedef struct
{
    int *id;
    char name[50];
} Student;

typedef union
{
    int *salary;
    char *addr;
} Data;

typedef enum
{
    RED,
    BLUE,
    GREEN
} Color;

void testScope()
{

    // Int example
    int *num = (int *)v_alloc(sizeof(int));
    *num = 22;
    printf("Int value: %d\n", *num);

    // Char example
    char *ch = (char *)v_alloc(sizeof(char));
    *ch = 'A';
    printf("Char value: %c\n", *ch);

    // String example
    char *str = (char *)v_alloc(20 * sizeof(char));
    strcpy(str, "Hello");
    printf("String value: %s\n", str);

    // Unsigned example
    unsigned char *uch = (unsigned char *)v_alloc(sizeof(unsigned char));
    if (!uch)
        return;
    *uch = 200;
    printf("Unsigned char value: %u\n", *uch);

    // Array example
    int *arr = (int *)v_alloc(5 * sizeof(int));
    if (!arr)
        return;
    for (int i = 0; i < 5; i++){
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Struct example with member pointer
    Student *pr = (Student *)v_alloc(sizeof(Student));
    pr->id = (int *)v_alloc(sizeof(int));
    *(pr->id) = 10;
    strcpy(pr->name, "Vector");
    printf("Student: %d, %s\n", *(pr->id), pr->name);

    // Enum example
    Color *color = (Color *)v_alloc(sizeof(Color));
    *color = GREEN;
    printf("Color: %d\n", *color);

    // Union example
    Data *data = (Data *)v_alloc(sizeof(Data));
    data->salary = (int *)v_alloc(sizeof(int));
    *(data->salary) = 500;
    printf("Salary: %d\n", *(data->salary));
}

int main()
{
    while (1)
    {
        testScope();
    }
    return 0;
}
