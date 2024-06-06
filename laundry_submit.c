#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "laundry.h"

void laundry_main(){
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option:");
    center_print("Submit Laundry (#1)");
    center_print("Receive Laundry (#2)");
    center_print("Records (#3)");
    center_print("Go to home (#0)");
    center_print("Press (B) or (b) to go back");
    char op;

 error:

    scanf(" %c",&op);

    switch (op) {
    case '1':
        system("cls");
        laundry_submit();
        break;

    case '2':
        system("cls");
        laundry_receive();
        break;

    case '3':
        system("cls");
        laundry_records();
        break;

    case '0':
        system("cls");
        home();
        break;
    case 'b':
        system("cls");
        admin_menu();
        break;
    case 'B':
        system("cls");
        admin_menu();
        break;

    default:
        printf("Invalid Input. Please try again\n");
        goto error;
        break;
    }


}
void laundry_submit() {
    char type_string[100];
    char type_string2[100];

    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please type your name: ");
    char name[100];
    scanf("%s", name);
    center_print("Please type your room number: ");
    int room;
    scanf("%d", &room);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");

    center_print("Please select:");
    center_print("Bedsheet (#1)");
    center_print("Pillow Cover (#2)");
    center_print("Bedsheet & Pillow Cover (#3)");

    center_print("Go to home (#0)");
    center_print("Press (B) or (b) to go back");

    char what_to_do;
    int amount=0;
    int amount2=0;
error:
    scanf(" %c", &what_to_do);
    switch (what_to_do) {
    case '1':
        system("cls");
        center_print("Enter the quantity:");
        scanf("%d", &amount2);
        strcpy(type_string, "Bedsheet Q");
        break;

    case '2':
        system("cls");
        center_print("Enter the quantity:");
        scanf("%d", &amount);
        strcpy(type_string, "Pillow Cover Q");
        break;

    case '3':
        system("cls");
        center_print("Enter the quantity of Bedsheet:");
        scanf("%d", &amount);
        center_print("Enter the quantity of Pillow Cover:");
        scanf("%d", &amount2);
        strcpy(type_string, "Bedsheet Q");
        strcpy(type_string2, "Pillow Cover Q");
        break;

    case '0':
        system("cls");
        home();
        break;
    case 'b':
        system("cls");
        laundry_main();
        break;
    case 'B':
        system("cls");
        laundry_main();
        break;

    default:
        printf("Invalid Input. Please try again\n");
        goto error;
        break;
    }

    // Open file to read the last laundry number
    FILE *file;
    file = fopen("laundry.csv", "r");
    int last_laundry_no = 0;
    char line[1000];

    // Read the last line of the file to get the last laundry number
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,", &last_laundry_no);
    }

    fclose(file);

    // Open the CSV file for appending
    file = fopen("laundry.csv", "a");
    if (file == NULL) {
        printf("Error opening CSV file for writing!\n");
        return;
    }

    // If file is empty, write the header
    long file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size == 0) {
        fprintf(file, "Laundry No,Name,Room,%s,%s\n", type_string, type_string2);
    }

    // Write laundry data to the CSV file
    if (what_to_do == '3') {
        fprintf(file, "%d,%s,%d,%d,%d\n", last_laundry_no + 1, name, room, amount, amount2);
    } else {
        fprintf(file, "%d,%s,%d,%d,%d\n", last_laundry_no + 1, name, room, amount,amount2);
    }

    // Close the CSV file
    fclose(file);

    center_print("Your laundry is successfully submitted");
    center_print("Press any key to continue");
    center_print("Press (B) or (b) to go back");
    char option2;
    scanf(" %c", &option2);

    if (option2 == 'B' || option2 == 'b') {
        system("cls");
        amount=0;
        amount2=0;
        laundry_main();
    } else {
        char temp;
        fflush(stdin);
        scanf("%c", &temp);
        system("cls");
        admin_menu();
    }
}


