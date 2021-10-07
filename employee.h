#include <stdio.h>
#include <stddef.h>

typedef struct
{
    long idNumber;
    char* name;
    char* phone;
    double salary;
} Employee, *pointerEmployee;

typedef const Employee *pointerConstEmployee;
