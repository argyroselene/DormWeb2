#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void resetFileForNewMeal(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "MealID\n"); 
    printf("The file is reset.\n");
    fclose(file);
}

int mealAlreadyTaken(char *filename, char *studentID) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char id[MAX_LENGTH];
        sscanf(line, "%[^,\n]", id);


        char *ptr = id;
        while (*ptr == ' ' || *ptr == '\t') ptr++;
        for (int i = strlen(ptr) - 1; i >= 0 && (ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\n'); i--)
            ptr[i] = '\0';

        if (strcmp(id, studentID) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


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

void mealtrack()
{
    char filename[] = "meal_records.csv";
menu:
     printf("\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option :\n");
    center_print("Update Meal Status (#1)\n");
    center_print("Start a new Meal (#2)\n");
    center_print("Go to Admin menu (#3)\n");


    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        char studentID[MAX_LENGTH];
add:
        center_print("Enter student ID: ");
        scanf("%s", studentID);

        if (mealAlreadyTaken(filename, studentID))
        {
            center_print("Meal has already been taken.\n");
            center_print("Please press B or b to Go Back else press any key to continue:\n");
            char c;
            scanf(" %c",&c);
            if(c=='B' || c=='b')
            {
                system("cls");
                goto menu;
            }
            else
            {

                goto add;
            }
        }
        else
        {
            updateMealStatus(filename, studentID);
            center_print("Please press B or b to go back , else press any other key to continue:\n");
            char c;
            scanf(" %c",&c);
            if(c=='B' || c=='b')
            {
                system("cls");
                goto menu;
            }
            else
            {

                goto add;
            }
        }
    }
    else if (choice == 2)
    {
        resetFileForNewMeal(filename);

        center_print("Please press any key to continue:\n");
            char c;
            scanf(" %c",&c);
            system("cls");
            goto menu;

    }
    else if(choice==3){
        system("cls");
        admin_menu();
    }

}

