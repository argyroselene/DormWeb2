#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

// Function to check if cleaning has already been done
int CleaningAlreadyDone(char *filename, char *RoomNumber) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; // Return -1 if there's an error opening the file
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char room[MAX_LENGTH];
        sscanf(line, "%[^,]", room);

        // Trim leading and trailing whitespace characters from id
        char *ptr = room;
        while (*ptr == ' ' || *ptr == '\t')
            ptr++;
        for (int i = strlen(ptr) - 1; i >= 0 && (ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\n'); i--)
            ptr[i] = '\0';

        if (strcmp(room, RoomNumber) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


void updateCleaningStatus(char *filename, char *RoomNumber) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\n", RoomNumber);
    center_print("Cleaning successfully updated.\n");
    fclose(file);
}

void cleaning() {
    char filename[] = "cleaning_records.txt";
    printf("\n\n\n\n\n\n\n\n\n\n");
//    center_print("Please choose an option :\n");
    center_print("Update Cleaning Status (#1)\n");
//    center_print("Start a new Meal (#2)\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        char RoomNumber[MAX_LENGTH];
        center_print("Enter room number: ");
        scanf("%s", RoomNumber);

        if (CleaningAlreadyDone(filename, RoomNumber)) {
            center_print("Cleaning has already been done.\n");
        } else {
            updateCleaningStatus(filename, RoomNumber);
        }
    }


}

