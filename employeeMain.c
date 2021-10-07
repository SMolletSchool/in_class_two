//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    //defined in employeeOne.c/employeeTwo.c, used here to reduce panic attacks in compiler
    pointerEmployee searchByNumber(const Employee table[], int tableSize, long givenNumber);
    pointerEmployee searchByName(const Employee table[], int tableSize, char* givenName);
    pointerEmployee searchBySalary(const Employee table[], int tableSize, double givenSalary);
    pointerEmployee searchByPhone(const Employee table[], int tableSize, char* givenPhone);

    //def in employeeTable.c, hence the extern
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    pointerEmployee matchPtr; //declare

    long wantedNumber = 4011l;
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, wantedNumber); //pass in table, table size, given number, should return null
    if (matchPtr != NULL) printf("employee %d located, at record %d\n", wantedNumber, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee %d not located in record\n", wantedNumber);

    wantedNumber = 161660l;
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, wantedNumber); //pass in table, table size, given number, should return null
    if (matchPtr != NULL) printf("employee %d located, at record %d\n", wantedNumber, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee %d not located in record\n", wantedNumber);

    char* wantedName = "Dorris Perl";
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedName);
    if (matchPtr != NULL) printf("employee %s located, at record %d\n", wantedName, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n",wantedName);

    wantedName = "Bobby Fischer";
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedName);
    if (matchPtr != NULL) printf("employee %s located, at record %d\n",wantedName, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n",wantedName);

    char* wantedPhone = "714-555-2749";
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedPhone);
    if (matchPtr != NULL) printf("employee %s located, at record %d\n",wantedPhone, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n",wantedPhone);

    wantedPhone = "714-555-9001";
    matchPtr = searchByName(EmployeeTable, EmployeeTableEntries, wantedPhone);
    if (matchPtr != NULL) printf("employee %s located, at record %d\n",wantedPhone, matchPtr - EmployeeTable); //ditto
    else printf("employee %s not located in record\n",wantedPhone);

    double wantedSalary = 4.50;
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, wantedSalary); //pass in table, table size, given number, should return null
    if (matchPtr != NULL) printf("employee %d located, at record %d\n", wantedSalary, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee %f not located in record\n", wantedSalary);

    wantedSalary = 0.002;
    matchPtr = searchByNumber(EmployeeTable, EmployeeTableEntries, wantedSalary); //pass in table, table size, given number, should return null
    if (matchPtr != NULL) printf("employee %d located, at record %d\n", wantedSalary, matchPtr - EmployeeTable); //Subtracting to get the offset, which is automatically divided by the correct length of bytes (32)
    else printf("employee %f not located in record\n", wantedSalary);

    

    
    
    return EXIT_SUCCESS; //funny value for main to just return 0
}