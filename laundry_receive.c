#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"laundry.h"
void laundry_receive() {
    int laundry_no;
    printf("Enter the laundry number to receive: \n");
    center_print("Press (B) or (b) to go back");
    scanf("%d", &laundry_no);
    char option2;;
        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            laundry_main();
        }

    // Open the complaints file
    FILE *file = fopen("laundry.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Create a temporary file to store non-resolved complaints
    FILE *temp_file = fopen("temp_laundry.txt", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[1000];
    int removed = 0; // Flag to indicate if complaint with given ID is removed

    // Read each line from the complaints file
    while (fgets(line, sizeof(line), file) != NULL) {
        int current_laundry_no;
        // Check if the line contains complaint information
        if (sscanf(line, "Laundry No: %d,", &current_laundry_no) == 1) {
            // If the complaint ID matches the one to be removed, skip it
            if (current_laundry_no == laundry_no) {
                removed = 1;
                continue;
            }
        }
        // Write non-removed complaints to the temporary file
        fprintf(temp_file, "%s", line);
    }

    fclose(file);
    fclose(temp_file);

    // Replace the original complaints file with the temporary file
    if (removed) {
        if (remove("laundry.txt") != 0) {
            printf("Error removing file!\n");
            return;
        }
        if (rename("temp_laundry.txt", "laundry.txt") != 0) {
            printf("Error renaming file!\n");
            return;
        }
        printf("Laundry with number %d received successfully.\n", laundry_no);
    } else {
        printf("Laundry with number %d not found.\n", laundry_no);
    }
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

