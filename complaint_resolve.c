#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complaint_resolve.h"

void complaint_resolve()
{
    int complaint_no;
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Enter the complaint number to resolve: ");
    scanf("%d", &complaint_no);

    FILE *file = fopen("complaints.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    FILE *temp_file = fopen("temp_complaints.csv", "w");
    if (temp_file == NULL)
    {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[1000];
    int removed = 0;
    int header_skipped = 0;

    if (fgets(line, sizeof(line), file) != NULL)
    {
        fprintf(temp_file, "%s", line);
        header_skipped = 1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        int current_complaint_no;

        if (sscanf(line, "%d,", &current_complaint_no) == 1)
        {
            if (current_complaint_no == complaint_no)
            {
                removed = 1;
                continue; 
            }
        }

        fprintf(temp_file, "%s", line);
    }

    fclose(file);
    fclose(temp_file);

    if (removed)
    {
        if (remove("complaints.csv") != 0)
        {
            printf("Error removing file!\n");
            return;
        }
        if (rename("temp_complaints.csv", "complaints.csv") != 0)
        {
            printf("Error renaming file!\n");
            return;
        }
        printf("Complaint with number %d resolved successfully.\n", complaint_no);
    }
    else
    {
        printf("Complaint with number %d not found.\n", complaint_no);
    }

    printf("Press any key to continue\n");
    char o;
    scanf(" %c", &o);
    if (1)
    {
        system("cls");
        admin_menu();
    }
}
