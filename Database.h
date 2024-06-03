#pragma once
typedef struct {
    char name[50];
    char id[15];
    char roomNumber[10];
    char department[10];
    char status[5];
    char phoneNumber[15];
    char semester[10];
} Database;
void displayDatabase(Database db);
void searchByRoomNumber(Database db[], int count, const char *roomNumber);
void searchByStatus(Database db[], int count, const char *status);
void searchByDepartment(Database db[], int count, const char *department);
void searchBySemester(Database db[], int count, const char *semester);

void database();

