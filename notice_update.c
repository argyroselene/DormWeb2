#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void notice_update() {
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please enter the date: ");
    center_print("Press (B) or (b) to go back");
    char option2;;
        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            login_admin();
        }
    char date[100];
    scanf(" %[^\n]", date);
    center_print("Please enter the notice: ");
    char notice[500];
     scanf(" %[^\n]", notice);

    system("cls");

    FILE *file;
    file = fopen("notice.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
    } else {
        fprintf(file, "%s %s\n", date, notice);
        fclose(file);
    }
    printf("\n\n\n\n\n\n\n\n\n\n");

    center_print("Your notice is successfully updated");
    center_print("Press (B) or (b) to go back");
    center_print("Press any key to continue");

        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            laundry_receive();
        }
    else{
    char temp;
    fflush(stdin);
    system("cls");
    home();
    }
}

