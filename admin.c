#include<stdio.h>
#include"admin.h"
#include<string.h>
#include<stdlib.h>
#include"complaint_resolve.h"

void draw_border(int length,char symbol)
{
    for(int a=0;a<length;a++)
        printf("%c",symbol);
    printf("\n");
}

void print_centre_wnl(char *s) //wnl means without new line
{
        printf("%95s","");
        printf("%*s%*s",10+strlen(s)/2,s,10-strlen(s)/2,"");
}

void login_admin(){
    FILE *fp;
    fp=fopen("admin_info.txt", "r");
    if(fp == NULL)
    {
        printf("Account Info Not Found(File absent)\n");
        home();
    }
    char name[101];
    char code[50];
    fscanf(fp," Name: %s",&name);
    fscanf(fp," Password: %s",&code);

    fclose(fp);

    char input_code[50];
    char input_name[100];
//    printf("%s\n",name); //Uncomment for (Debug)
//    printf("%s",code); //Uncomment for (Debug)
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("%120s","Enter UserName: ");
    scanf("%s",&input_name);
    printf("%120s","Enter Passcode: ");
    scanf("%s",&input_code);

//   printf("%s\n",input_name);//Uncomment for (Debug)
//   printf("%s",input_code);//Uncomment for (Debug)


   if(strcmp(code, input_code)==0  && strcmp(name,input_name)== 0)

   {
       system("cls");
       draw_border(209,'-');
       printf("\n");
       center_print("Welcome Admin");
       printf("\n");
       draw_border(209,'-');

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
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option:");
    center_print("Database (#1)");
    center_print("Search Student Information (#2)");
    center_print("Cleaning Log (#3)");
    center_print("Laundry Maintenance (#4)");
    center_print("Meal Tracking (#5)");
    center_print("Complaint (#6)");
    center_print("Go to home (#0)");

    int what_to_do;

error:
     scanf("%d",&what_to_do);
        switch (what_to_do){
        case 1:
            system("cls");
            //database();
            break;

        case 2:
            system("cls");
            search_student();
            break;

        case 3:
            system("cls");
            //cleaning_log();
            break;

      	 case 4:
            system("cls");
            //laundry();
            break;

        case 5:
            system("cls");
            //meal_tracking();
            break;

        case 6:
            system("cls");
            complaint_resolve();
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
