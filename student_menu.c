#include <stdio.h>
#include <string.h>
#include "dashboard.h"
#include "globals.h"

void student_menu()
{
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

    char what_to_do;

error:
    scanf(" %c", &what_to_do);
    switch (what_to_do)
    {
    case '1':
        system("cls");
        dashboard();
        break;

    case '2':
        system("cls");
        // gym();
        break;

    case '3':
        system("cls");
        study();
        break;

    case '4':
        system("cls");
        cleaning();
        break;

    case '5':
        system("cls");
        // notice();
        break;

    case '6':
        system("cls");
        complaint_submit();
        break;
    case '7':
        system("cls");
        menu();
        break;
    case '8':
        system("cls");
        // washing_machine();
        break;
    case '0':
        system("cls");
        home();
        break;

    default:
        printf("Invalid Input. Please try again\n");
        goto error;
        break;
    }
}
