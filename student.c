#include<stdio.h>
#include"student.h"
#include<string.h>
#include<stdlib.h>
void login_student(){
    char username[50];
    char passcode[50];
    FILE *fp;
    struct account acc;
    fp=fopen("student_info.txt", "r");
    if(fp == NULL)
    {
        printf("Account Info Not Found(File absent)\n");
        home();
    }
    printf("\n\n\n\n\n\n\n\n\n\n");

    printf("%120s", "Enter your name: ");
    scanf("%s",username);
    fscanf(fp," Username: %s",&acc.username);
    printf("%120s","Enter your password: ");
    scanf("%s",passcode);
    unsigned int pass=encryption(passcode);
    fscanf(fp," Password: %lld",&acc.passcode);
    if(strcmp(username,acc.username)==0 && pass==acc.passcode){
        system("cls");
       draw_border(209,'-');
       printf("\n");
       center_print("Welcome");
       printf("\n");
       draw_border(209,'-');
       printf("\n\n\n\n\n\n\n\n\n\n");
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
        switch (what_to_do){
        case 1:
            system("cls");
            //dashboard();
            break;

        case 2:
            system("cls");
            //gym();
            break;

        case 3:
            system("cls");
            //study();
            break;

      	 case 4:
            system("cls");
            //cleaning();
            break;

        case 5:
            system("cls");
            //notice();
            break;

        case 6:
            system("cls");
            //submit_complaint();
            break;
        case 7:
            system("cls");
            //menu();
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
            goto error;
            break;
        }
    }
    else{

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
