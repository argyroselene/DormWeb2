#include <stdio.h>
#include "student.h"
#include <string.h>
#include <stdlib.h>
#include "dashboard.h"
#include "Cleaning_log.h"
void login_student()
{
    char username[101];
    char passcode[101];
    char name[100];
    FILE *fp;
    struct account acc;
    fp=fopen("student_info.txt", "r");
    if(fp == NULL)
    {
        printf("Account Info Not Found(File absent)\n");
        home();
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("%90s", "Enter your username: ");
    scanf("%s", username);
    printf("%90s", "Enter your password: ");
    scanf("%s", passcode);
    unsigned long pass=encryption(passcode);
    int found = 0;

   // Read each record from the file and check for matching username and password
    while (fscanf(fp, " Name: %[^\n]\n ID: %*lu\n Username: %s\n Password: %lu\n", acc.name, acc.username, &acc.passcode) == 3)
    {
        if (strcmp(username, acc.username) == 0 && pass == acc.passcode)
        {
            found = 1;
            break; // Exit loop if match found
        }
    }

    // fclose(fp); // Close the file

    if (found)
    {
        system("cls");
        draw_border(312, '-');
        printf("\n");
        center_print("Welcome");
        printf("\n");
        strcpy(name,acc.name);
        draw_border(312, '-');
        printf("\n\n\n\n\n\n\n\n");
        center_print("Please choose an option:");
        center_print("Dashboard (#1)");
        center_print("Gym Equipment Status (#2)");
        center_print("Study Room Occupancy (#3)");
        center_print("Update Cleaning Log (#4)");
        center_print("Notice Update (#5)");
        center_print("Submit Complaint (#6)");
        center_print("Food Menu (#7)");
        center_print("Washing Machine Slots (#8)");
        center_print("Go to home (#0)");

        int what_to_do;

error:
        scanf("%d",&what_to_do);
        switch (what_to_do)
        {
        case 1:
            system("cls");
            dashboard(acc.name);
            break;

        case 2:
            system("cls");
            //gym();
            break;

        case 3:
            system("cls");
            study();
            break;

        case 4:
            system("cls");
            cleaning();
            break;

        case 5:
            system("cls");
            //notice();
            break;

        case 6:
            system("cls");
            complaint_submit();
            break;
        case 7:
            system("cls");
            menu();
            break;
        case 8:
            system("cls");
            //washing_machine();
            break;
        case 0:
            system("cls");
            home();
            break;

        default:
            printf("Invalid Input. Please try again\n");
            system("cls");
            goto error;
            break;
        }
    }
    else
    {

        system("cls");
        printf("Invalid  Name or Code,GO Back(B)\n");
        char option;
        scanf(" %c",&option);

        if(option == 'B' || option == 'b')

        {
            system("cls");
            home();
        }
    }
    fclose(fp);
}
