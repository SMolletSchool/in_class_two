#include <string.h>
#include "employee.h"

pointerEmployee searchByNumber (pointerConstEmployee ptr, int TableSize, long givenNumber) {
    const pointerConstEmployee endPtr = ptr + TableSize;

    for  (;ptr < endPtr; ptr++) {
        if (ptr -> idNumber == givenNumber) return (pointerEmployee) ptr;
    }
    return NULL;
}

pointerEmployee searchByName (pointerConstEmployee ptr, int TableSize, char* givenName) {
    const pointerConstEmployee endPtr = ptr + TableSize;

    for  (;ptr < endPtr; ptr++) {
        if (strcmp(ptr -> name, givenName) == 0) return (pointerEmployee) ptr; //when strcmp() returns 0, that means there are 0 differences
    }
    return NULL;
}

pointerEmployee searchBySalary (pointerConstEmployee ptr, int TableSize, double givenSalary) {
    const pointerConstEmployee endPtr = ptr + TableSize;

    for  (;ptr < endPtr; ptr++) {
        if (ptr -> salary == givenSalary) return (pointerEmployee) ptr;
    }
    return NULL;
}

pointerEmployee searchByPhone (pointerConstEmployee ptr, int TableSize, char* givenPhone) {
    const pointerConstEmployee endPtr = ptr + TableSize;

    for  (;ptr < endPtr; ptr++) {
        if (strcmp(ptr -> phone, givenPhone) == 0) return (pointerEmployee) ptr;
    }
    return NULL;
}