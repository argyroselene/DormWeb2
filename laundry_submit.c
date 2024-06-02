#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void center_print(char *s);

void laundry(){
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option:");
    center_print("Submit Laundry (#1)");
    center_print("Receive Laundry (#2)");
    center_print("Records (#3)");
    center_print("Go to home (#0)");
    char op;
error:
    scanf(" %c", &op);

    switch (op) {
    case '1':
        system("cls");
        laundry_submit();
        break;

    case '2':
        system("cls");
        //laundry_receive();
        break;

    case '3':
        system("cls");
        //records();
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

    char what_to_do;
    int amount;
    int amount2;
error:
    scanf(" %c", &what_to_do);
    switch (what_to_do) {
    case '1':
        system("cls");
        center_print("Enter the quantity:");
        scanf("%d", &amount);
        strcpy(type_string, "Bedsheet");
        break;

    case '2':
        system("cls");
        center_print("Enter the quantity:");
        scanf("%d", &amount);
        strcpy(type_string, "Pillow Cover");
        break;

    case '3':
        system("cls");
        center_print("Enter the quantity of Bedsheet:");
        scanf("%d", &amount);
        center_print("Enter the quantity of Pillow Cover:");
        scanf("%d", &amount2);
        strcpy(type_string, "Bedsheet");
        strcpy(type_string2, "Pillow Cover");

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
    // Open file to read the last number
    FILE *file;
    file = fopen("laundry.txt", "r");
    int last_complaint_no = 0;
    char line[1000];

    // Read the last line of the file to get the last complaint number
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "Laundry No: %d,", &last_complaint_no);
    }

    fclose(file);

    // storing all the info in a file (append)
    file = fopen("laundry.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
    }
    else if(what_to_do=='3'){
        fprintf(file, "Laundry No: %d, Name: %s, Room: %d, %s Quantity: %d, %s Quantity: %d\n", last_complaint_no + 1, name, room, type_string, amount, type_string2, amount2);
        fclose(file);
    }

    else {
        fprintf(file, "Laundry No: %d, Name: %s, Room: %d, %s, Quantity: %d\n", last_complaint_no + 1, name, room, type_string, amount);
        fclose(file);
    }

    center_print("Your laundry is successfully submitted");
    center_print("Press any key to continue");
    char temp;
    fflush(stdin);
    scanf("%c", &temp);
    system("cls");
    home();
}

