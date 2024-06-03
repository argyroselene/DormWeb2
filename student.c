#include <stdio.h>
#include "student.h"
#include <string.h>
#include <stdlib.h>
#include "dashboard.h"
#include "Cleaning_log.h"
#include "globals.h"

void login_student()
{
    char username[101];
    char passcode[101];
    FILE *fp;
    struct account acc;
    fp = fopen("student_info.csv", "r");
    if (fp == NULL)
    {
        printf("Account Info Not Found(File absent)\n");
        home();
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("%90s", "Enter your username: ");
    scanf("%s", username);
    printf("%90s", "Enter your password: ");
    scanf("%s", passcode);
    unsigned long pass = encryption(passcode);
    int found = 0;

    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%lu", acc.name, acc.id, acc.username, &acc.passcode);
        if (strcmp(username, acc.username) == 0 && pass == acc.passcode)
        {
            found = 1;
            break;
        }
    }

        if (found)
        {
            system("cls");
            draw_border(312, '-');
            printf("\n");
            center_print("Welcome");
            printf("\n");
            strcpy(logged_in_student_name, acc.name);
            //printf("%s",logged_in_student_name);
            draw_border(312, '-');
            student_menu();
        }
        else
        {
            system("cls");
            printf("Invalid  Name or Code,GO Back(B)\n");
            char option;
            scanf(" %c", &option);

            if (option == 'B' || option == 'b')
            {
                system("cls");
                home();
            }
        }

}
