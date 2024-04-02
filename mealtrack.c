#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

// Function to reset the meal records file
void resetFileForNewMeal(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("The file is reset.\n");
    fclose(file);
}

// Function to check if the meal has already been taken
int mealAlreadyTaken(char *filename, char *studentID) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; // Return -1 if there's an error opening the file
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char id[MAX_LENGTH];
        sscanf(line, "%[^,]", id);

        // Trim leading and trailing whitespace characters from id
        char *ptr = id;
        while (*ptr == ' ' || *ptr == '\t')
            ptr++;
        for (int i = strlen(ptr) - 1; i >= 0 && (ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\n'); i--)
            ptr[i] = '\0';

        if (strcmp(id, studentID) == 0) {
            fclose(file);
            return 1; // Return 1 if the meal has already been taken
        }
    }

    fclose(file);
    return 0; // Return 0 if the meal hasn't been taken yet
}

// Function to update the meal status in the file
void updateMealStatus(char *filename, char *studentID) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\n", studentID);
    printf("Meal successfully updated.\n");
    fclose(file);
}

void mealtrack() {
    char filename[] = "meal_records.txt";
    printf("Please choose an option :\n");
    printf("Update Meal Status (#1)\n");
    printf("Start a new Meal (#2)\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        char studentID[MAX_LENGTH];
        printf("Enter student ID: ");
        scanf("%s", studentID);

        if (mealAlreadyTaken(filename, studentID)) {
            printf("Meal has already been taken.\n");
        } else {
            updateMealStatus(filename, studentID);
        }
    } else if (choice == 2) {
        resetFileForNewMeal(filename);
    }

}
