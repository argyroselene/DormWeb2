#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"complaint_submit.h"

void complaint_submit() {
    char type_string[100];

    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please type your room number: ");
    int room;
    scanf("%d", &room);
    system("cls");
    center_print("Please select the type of complaint:");
    center_print("Electrical (#1)");
    center_print("Plumbing (#2)");
    center_print("Carpentry (#3)");
    center_print("Internet (#4)");
    center_print("Go to home (#0)");

    int what_to_do;

error:
    scanf("%d", &what_to_do);
    switch (what_to_do) {
    case 1:
        system("cls");
        strcpy(type_string, "Electrical");
        break;

    case 2:
        system("cls");
        strcpy(type_string, "Plumbing");
        break;

    case 3:
        system("cls");
        strcpy(type_string, "Carpentry");
        break;

    case 4:
        system("cls");
        strcpy(type_string, "Internet");
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
    // Taking problem and available time as input
    char problem[500];
    center_print("Please mention your problem");
    scanf(" %[^\n]", problem);
    system("cls");
    center_print("Please mention your available time and date");
    char availability[150];
    scanf(" %[^\n]", availability);

    // Open file to read the last complaint number
    FILE *file;
    file = fopen("complaints.txt", "r");
    int last_complaint_no = 0;
    char line[1000];

    // Read the last line of the file to get the last complaint number
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "Complaint No: %d,", &last_complaint_no);
    }

    fclose(file);

    // storing all the info in a file (append)
    file = fopen("complaints.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
    } else {
        fprintf(file, "Complaint No: %d, Room: %d, Type: %s, Problem: %s, Availability: %s\n", last_complaint_no + 1, room, type_string, problem, availability);
        fclose(file);
    }

    center_print("Your complaint is successfully submitted");
    center_print("Press any key to continue");
    char temp;
    fflush(stdin);
    scanf("%c", &temp);
    system("cls");
    home();
}
