#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Database.h"

void displayDatabase(Database db) {
    printf("Name: %s, ID: %s, Room Number: %s, Department: %s, Status: %s, Phone Number: %s, Semester: %s\n",
           db.name, db.id, db.roomNumber, db.department, db.status, db.phoneNumber, db.semester);
}

void searchByRoomNumber(Database db[], int count, const char *roomNumber) {
    int found = 0;
    printf("Students in room number %s:\n\n", roomNumber);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].roomNumber, roomNumber) == 0) {
            displayDatabase(db[i]);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No students found in room number %s\n", roomNumber);

    }
}


void searchByStatus(Database db[], int count, const char *status) {
    printf("Students with payment status %s:\n\n", status);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].status, status) == 0) {
            displayDatabase(db[i]);
            printf("\n");
        }
    }
}

void searchByDepartment(Database db[], int count, const char *department) {
    printf("Students in department %s:\n\n", department);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].department, department) == 0) {
            displayDatabase(db[i]);
            printf("\n");
        }
    }
}

void searchBySemester(Database db[], int count, const char *semester) {
    int found = 0;
    printf("Students in semester %s:\n\n", semester);
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i].semester, semester) == 0) {
            displayDatabase(db[i]);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No students found in semester %s\n", semester);

    }
}

void database() {
    FILE *file;
    char line[256];
    Database db[100];
    int count = 0;
    int choice;
    char input[50];

    file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Error reading header\n");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\r\n")] = 0;


        sscanf(line, "%49[^,],%14[^,],%9[^,],%9[^,],%4[^,],%14[^,],%9[^\n]",
               db[count].name, db[count].id, db[count].roomNumber,
               db[count].department, db[count].status, db[count].phoneNumber, db[count].semester);
        count++;
    }

    fclose(file);
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Enter Criteria Based on which you want to search:");
    center_print("1.Room Number");
    center_print("2.Payment Status");
    center_print("3.Department");
    center_print("4.Semester");
data:
    center_print("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            center_print("Enter Room Number: ");
            scanf("%s", input);
            searchByRoomNumber(db, count, input);
            break;
        case '2':
            center_print("Enter Payment Status: ");
            scanf("%s", input);
            searchByStatus(db, count, input);
            break;
        case '3':
            center_print("Enter Department: ");
            scanf("%s", input);
            searchByDepartment(db, count, input);
            break;
        case '4':
            center_print("Enter Semester: ");
            scanf("%s", input);
            searchBySemester(db, count, input);
            break;
        default:
            center_print("Invalid choice.Please try again\n");
            goto data;
    }
    center_print("Press any key to go back:");
    char x;
    scanf(" %c",&x);
    if(x){
        system("cls");
        admin_menu();
    }
}





