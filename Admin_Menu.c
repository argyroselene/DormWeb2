#include<stdio.h>
#include<stdlib.h>
#include"admin.h"
#include"search_student.h"
#include"complaint_resolve.h"
#include"CleaningLog_Admin.h"

void admin_menu() {
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option:");
    center_print("Database (#1)");
    center_print("Search Student Information (#2)");
    center_print("Cleaning Log (#3)");
    center_print("Laundry Maintenance (#4)");
    center_print("Meal Tracking (#5)");
    center_print("Complaint (#6)");
    center_print("Go to home (#0)");

    char what_to_do;

error:
     scanf(" %c",&what_to_do);
        switch (what_to_do) {
        case '1':
            system("cls");
            //database();
            break;

        case '2':
            system("cls");
            search_student();
            break;

        case '3':
            system("cls");
            cleaning_log();
            break;

      	case '4':
            system("cls");
            laundry_main();
            break;

        case '5':
            system("cls");
            mealtrack();
            break;

        case '6':
            system("cls");
            complaint_resolve();
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
