#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
#include "Cleaning_log.h"

void resetFileForNewClean(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    center_print("The file is reset.\n");
    fclose(file);
}

void GoBack(){
    char option2;
    scanf(" %c",&option2);

    if(option2 == 'B' || option2 == 'b') {
        system("cls");
        cleaning_log();
    }
    else {
        center_print("Invalid input. Please try again");
        GoBack();
    }
}

void viewAllCleaningStatus(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void viewComments(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void viewCleanedRooms(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        if (strstr(line, "Clean") != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
}

void viewUncleanedRooms(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        if (strstr(line, "Unclean") != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
}

void cleaning_log() {
    char filename[] = "cleaning_records.txt";
    char comment_filename[] = "cleaning_comment.txt";

    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option :\n");
    center_print("View Cleaning Status for a Room (#1)\n");
    center_print("Start a new day for cleaning (#2)\n");
    center_print("View All Cleaning Status (#3)\n");
    center_print("View Comments (#4)\n");
    center_print("Go to Admin Menu(#5)\n");

    char choice;
    scanf(" %c", &choice);
    system("cls");
    if (choice == '1') {
        printf("\n\n\n\n\n\n\n\n\n\n");
        char RoomNumber[MAX_LENGTH];
        printf("%90s","Enter room number: ");
        scanf("%s", RoomNumber);
        printf("\n");
        if (CleaningAlreadyDone(filename, RoomNumber)) {
            center_print("Cleaning has already been done.\n");
        } else {
            center_print("Cleaning has not been done yet.\n");
        }
        center_print("Go Back (#B)");
        GoBack();

    } else if (choice == '2') {
        printf("\n\n\n\n\n\n\n\n\n\n");
        resetFileForNewClean(filename);
        center_print("Go Back (#B)");
        GoBack();

    } else if (choice == '3') {
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("%90s","Do you want to see cleaned (C) or uncleaned (U) rooms? ");
        char cleanedOption;
        scanf(" %c", &cleanedOption);

        if (cleanedOption == 'C' || cleanedOption == 'c') {
            printf("Cleaned rooms:\n");
            viewCleanedRooms(filename);
        } else if (cleanedOption == 'U' || cleanedOption == 'u') {
            printf("Uncleaned rooms:\n");
            viewUncleanedRooms(filename);
        } else {
            printf("Invalid input. Please try again0    .\n");
            cleaning_log();
            return;
        }
        center_print("Go Back (#B)");
        GoBack();

    } else if (choice == '4') {
        printf("\n\n\n\n\n\n\n\n\n\n");
        viewComments(comment_filename);
        center_print("Go Back (#B)");
        GoBack();

    } else if (choice == '5') {
        printf("\n\n\n\n\n\n\n\n\n\n");
        system("cls");
        admin_menu();

    } else {
        printf("\n\n\n\n\n\n\n\n\n\n");
        system("cls");
        printf("Invalid input. Please try again.");
        cleaning_log();
    }
}

