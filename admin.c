#include<stdio.h>
#include"admin.h"
#include<stdlib.h>

void draw_border(int length,char symbol)
{
    for(int a=0;a<length;a++)
        printf("%c",symbol);
    printf("\n");
}

void print_centre_wnl(char *s)
{
        printf("%70s","");
        printf("%*s%*s",10+strlen(s)/2,s,10-strlen(s)/2,"");
}

void get_masked_password(char *password, int max_len) {
    int index = 0;
    char ch;

    while (1) {
        ch = getch();

        if (ch == '\r' || ch == '\n') {
            password[index] = '\0';
            break;
        } else if (ch == '\b') {
            if (index > 0) {
                index--;
                printf("\b \b");
        } else if (index < max_len - 1) {
            password[index] = ch;
            index++;
            printf("*");
        }
    }
}


void login_admin() {
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

    printf("\n\n\n\n\n\n\n\n\n\n");
    print_centre_wnl("Enter UserName: ");
    scanf("%s",&input_name);
    print_centre_wnl("Enter Passcode: ");

    get_masked_password(input_code, sizeof(input_code));


   if(strcmp(code, input_code)==0  && strcmp(name,input_name)== 0)

   {
       system("cls");
       draw_border(336,'-');
       printf("\n");
       center_print("Welcome Admin");
       printf("\n");
       draw_border(336,'-');
       admin_menu();

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
}
