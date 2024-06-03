#include <stdio.h>
#include <string.h>
#include "dashboard.h"
#include "globals.h"

void dashboard()
{
    FILE *dashboard;
    struct Student student;

    dashboard = fopen("database.csv", "r");
    if (dashboard == NULL)
    {
        printf("Error: Unable to open the file.\n");
        return;
    }

    int found = 0;
    char line[512];
    while (fgets(line, sizeof(line), dashboard))
    {
        line[strcspn(line, "\n")] = '\0';

        sscanf(line, "%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^\n]", student.name, student.id, &student.room, student.department, student.payment_status, student.contact_number, student.semester);

        if (strcmp(student.name, logged_in_student_name) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        system("cls");
        printf("\nStudent Information:\n");
        printf("Name: %s\n", student.name);
        printf("ID: %s\n", student.id);
        printf("Department: %s\n", student.department);
        printf("Payment Status: %s\n", student.payment_status);
        printf("Contact Number: %s\n", student.contact_number);
        printf("Current Semester: %s\n", student.semester);
        printf("\n\n\n\n");
        printf("Press any key to continue\n");
        char temp;
        fflush(stdin);
        scanf(" %c", &temp);
        system("cls");
        student_menu();
    }
    else
    {
        printf("Student not found.\n");
    }

    fclose(dashboard);
}




















