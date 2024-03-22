#include <stdio.h>
#include <string.h>
#include "dashboard.h"

void dashboard(char* name)
{

    FILE *dashboard;
    struct Student student;


    dashboard = fopen("database.txt", "r");
    if (dashboard == NULL)
    {
        printf("Error: Unable to open the file.\n");
    }

    int found = 0;
    while (fscanf(dashboard, "%[^,],%[^,],%d,%[^,],%[^,],%[^\n]", student.name, student.id, &student.room, student.department, student.payment_status, student.contact_number) != EOF)
    {
         if (student.name[0] == '\n') // Corrected comparison
    {
        // Skip leading newline characters
        memmove(student.name, student.name + 1, strlen(student.name));
    }

        if (strcmp(student.name,name) == 0)
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
        printf("\n\n\n\n");
        printf("Press any key to continue\n");
        char temp;
        fflush(stdin);
        scanf("%c", &temp );
        system("cls");
        home();
    }
//     else {
//        printf("Error: Student with ID '%s' not found.\n", input_id);
//        printf("Press (B) to go back to home\n");
//       char option;
//       scanf(" %c",&option);
//
//    if(option == 'B' || option == 'b')
//
//       {
//           system("cls");
//           home();
//       }
//    }
//

    fclose(dashboard);
}



















