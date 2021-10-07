#include <string.h>
#include "employee.h"

/*
5 (!!!) defined functions
ptr: points to table to search
tableSize: size of table
targetPtr: points to value to be searched in table
functionPtr: points to comparison function and performs proper check


this all results in the duplicate code being abstracted out.
*/

pointerEmployee searchTable (pointerConstEmployee ptr, int TableSize, const void *targetPtr, int (*FunctionPtr)(const void *, pointerConstEmployee)) { //static, for functions = only usable in this file. Basically private.
    pointerConstEmployee endPtr = ptr + TableSize;

    for  (;ptr < endPtr; ptr++) {
        if ((*FunctionPtr)(targetPtr, ptr) == 0) return (pointerEmployee) ptr;
    }
    return NULL;
}

static int compareNumber(const void * targetPtr, pointerConstEmployee tableValuePtr) { //ditto
    return * (long *) targetPtr != tableValuePtr -> idNumber; //return the boolean value of the comparison of the pointer of the typecasted to long pointer targetPtr compared to the table value ptr pointed to idnumber
}

static int compareName(const void * targetPtr, pointerConstEmployee tableValuePtr) { //ditto
    return strcmp((char *) targetPtr, tableValuePtr -> name); 
}

static int compareSalary(const void * targetPtr, pointerConstEmployee tableValuePtr) { //ditto
    return * (double *) targetPtr != tableValuePtr -> salary;
}

static int comparePhone(const void * targetPtr, pointerConstEmployee tableValuePtr) { //ditto
    return strcmp((char *) targetPtr, tableValuePtr -> phone); 
}

pointerEmployee searchByNumber(pointerConstEmployee ptr, int size, long number) { //Wrapper function. This is used in main.
    return searchTable(ptr, size, &number, compareNumber); //Pass number ADDRESS
}

pointerEmployee searchByName(pointerConstEmployee ptr, int size, char* name) { //ditto
    return searchTable(ptr, size, name, compareName);
}

pointerEmployee searchBySalary(pointerConstEmployee ptr, int size, long number) { //Wrapper function. This is used in main.
    return searchTable(ptr, size, &number, compareSalary); //Pass number ADDRESS
}

pointerEmployee searchByPhone(pointerConstEmployee ptr, int size, char* name) { //ditto
    return searchTable(ptr, size, name, comparePhone);
}