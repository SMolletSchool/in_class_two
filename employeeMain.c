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

    long searchNumber = 1001;
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, searchNumber); //pass in table, table size, given number
    if (matchPtr != NULL) printf("employee %d located, at record %d\n", 1001l, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee %d not located in record\n", searchNumber);

    searchNumber = 9001;
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, searchNumber); //pass in table, table size, given number
    if (matchPtr != NULL) printf("employee %d located, at record %d\n", 1001l, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee %d not located in record\n", searchNumber);

    char* wantedName = "Tammy Franklin";
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedName);
    if (matchPtr != NULL) printf("employee %s, located, at record %d\n", wantedName, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n", wantedName);

    char* wantedName = "Dr. Doofenschmirtz";
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedName);
    if (matchPtr != NULL) printf("employee %s, located, at record %d\n", wantedName, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n", wantedName);

    double wantedSalary = 8.78;
    matchPtr = searchBySalary(EmployeeTable, EmployeeTableEntries, wantedSalary); //ditto
    if (matchPtr != NULL) printf("employee %f located, at record %d\n", wantedSalary, matchPtr - EmployeeTable); //ditto
    else printf("employee %f not located in record\n", wantedSalary);

    double wantedSalary = 11.111;
    matchPtr = searchBySalary(EmployeeTable, EmployeeTableEntries, wantedSalary); //ditto
    if (matchPtr != NULL) printf("employee %f located, at record %d\n", wantedSalary, matchPtr - EmployeeTable); //ditto
    else printf("employee %f not located in record\n", wantedSalary);

    char* wantedPhone = "714-555-2749";
    matchPtr = searchByPhone(EmployeeTable, EmployeeTableEntries, wantedPhone);
    if (matchPtr != NULL) printf("employee with phone number %s, located, at record %d\n", wantedPhone, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n", wantedPhone);

    char* wantedPhone = "909-WORKERS-RUS";
    matchPtr = searchByPhone(EmployeeTable, EmployeeTableEntries, wantedPhone);
    if (matchPtr != NULL) printf("employee with phone number %s, located, at record %d\n", wantedPhone, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n", wantedPhone);

    return EXIT_SUCCESS; //funny value for main to just return 0
}