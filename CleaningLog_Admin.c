#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
#include "Cleaning_log.h"

// Function to reset the cleaning records file
void resetFileForNewClean(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("The file is reset.\n");
    fclose(file);
}
void GoBack(){
    char option2;;
        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            cleaning_log();
        }
        else {center_print("Invalid input. Please try again");
        GoBack();
    }
 }
void cleaning_log() {
    char filename[] = "cleaning_records.txt";
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option :\n");
    center_print("View Cleaning Status (#1)\n");
    center_print("Start a new day for cleaning (#2)\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        char RoomNumber[MAX_LENGTH];
        center_print("Enter room number: ");
        scanf("%s", RoomNumber);

        if (CleaningAlreadyDone(filename, RoomNumber)) {
            center_print("Cleaning has already been done.\n");
        } else {
            center_print("Cleaning has not been done yet\n");
        }
        center_print("Go Back (#B)");
        GoBack();

    }
    else if (choice == 2) {
        resetFileForNewClean(filename);
    }

}

