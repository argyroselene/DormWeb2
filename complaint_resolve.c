#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"complaint_resolve.h"
void complaint_resolve() {
    int complaint_no;
    printf("Enter the complaint number to resolve: ");
    scanf("%d", &complaint_no);

    // Open the complaints file
    FILE *file = fopen("complaints.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Create a temporary file to store non-resolved complaints
    FILE *temp_file = fopen("temp_complaints.txt", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[1000];
    int removed = 0; // Flag to indicate if complaint with given ID is removed

    // Read each line from the complaints file
    while (fgets(line, sizeof(line), file) != NULL) {
        int current_complaint_no;
        // Check if the line contains complaint information
        if (sscanf(line, "Complaint No: %d,", &current_complaint_no) == 1) {
            // If the complaint ID matches the one to be removed, skip it
            if (current_complaint_no == complaint_no) {
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
        if (remove("complaints.txt") != 0) {
            printf("Error removing file!\n");
            return;
        }
        if (rename("temp_complaints.txt", "complaints.txt") != 0) {
            printf("Error renaming file!\n");
            return;
        }
        printf("Complaint with number %d resolved successfully.\n", complaint_no);
    } else {
        printf("Complaint with number %d not found.\n", complaint_no);
    }
}
