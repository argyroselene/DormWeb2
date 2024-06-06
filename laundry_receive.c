#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laundry.h"

void laundry_receive() {
    int laundry_no;
    printf("Enter the laundry number to receive: \n");
    scanf("%d", &laundry_no); 

   
    FILE *file = fopen("laundry.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

  
    FILE *temp_file = fopen("temp_laundry.csv", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[1000];
    int removed = 0; 
    int header_written = 0; 


    while (fgets(line, sizeof(line), file) != NULL) {
        int current_laundry_no;
     
        if (!header_written) {
            fprintf(temp_file, "%s", line);
            header_written = 1;
            continue;
        }

       
        sscanf(line, "%d,", &current_laundry_no);
      
        if (current_laundry_no == laundry_no) {
            removed = 1;
            continue;
        }
     
        fprintf(temp_file, "%s", line);
    }

    fclose(file);
    fclose(temp_file);


    if (removed) {
        if (remove("laundry.csv") != 0) {
            printf("Error removing file!\n");
            return;
        }
        if (rename("temp_laundry.csv", "laundry.csv") != 0) {
            printf("Error renaming file!\n");
            return;
        }
        printf("Laundry with number %d received successfully.\n", laundry_no);
    } else {
        printf("Laundry with number %d not found.\n", laundry_no);
        remove("temp_laundry.csv"); 
    }


    center_print("Press (B) or (b) to go back");
    center_print("Press any key to continue");
    char option2;
    scanf(" %c", &option2);

    if (option2 == 'B' || option2 == 'b') {
        system("cls");
        laundry_main();
    } else {
        fflush(stdin);
        system("cls");
        home();
    }
}





