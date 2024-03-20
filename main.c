#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "student.h"
#include "search_student.h"

void center_print(char *s){

    printf("%90s","");
    printf("%*s%*s\n",10+strlen(s)/2,s,10-strlen(s)/2,"");

}

void home(){

    printf("\n\n\n\n\n\n\n\n\n\n");

    center_print("Welcome to DormWeb");
    printf("\n\n\n\n");

    center_print("Choose a Window:");
    center_print("Admin login (#1)");
    center_print("Student login (#2)");

    int window;
    printf("\n\n%110s","Please Select (1/2): ");
    scanf("%d",&window);
    if(window==1){
        system("cls");
        login_admin();
    }
    else if(window==2){
        system("cls");
        login_student();
    }
    else{
        center_print("Invalid input. Please select again.\n");
        system("cls");
        home();
    }

}

int main(){


    home();


}
