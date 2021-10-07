//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    //defined in employeeOne.c/employeeTwo.c, used here to reduce panic attacks in compiler
    pointerEmployee searchByNumber(const Employee table[], int tableSize, long givenNumber);
    pointerEmployee searchByName(const Employee table[], int tableSize, char* givenName);

    //def in employeeTable.c, hence the extern
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    pointerEmployee matchPtr; //declare
    long wantedNumber;
    printf("Search for employee by ID:\n");
    scanf("%ld", &wantedNumber);
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, wantedNumber); //pass in table, table size, given number, should return null

    if (matchPtr != NULL) printf("employee %d located, at record %d\n", wantedNumber, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee not located in record\n");

    char* wantedName;
    printf("Search for employee by Name:\n");
    scanf("%s", wantedName);
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedName);
    if (matchPtr != NULL) printf("employee, Tony Bobcat, located, at record %d\n", matchPtr - EmployeeTable); //ditto
    else printf("employee not located in record\n");

    return EXIT_SUCCESS; //funny value for main to just return 0
}