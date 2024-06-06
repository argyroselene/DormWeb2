#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laundry.h"

void writeLaundryToCSV(const char *csvFileName, int laundryNo) {

    FILE *csvFile = fopen(csvFileName, "a");
    if (csvFile == NULL) {
        printf("Error opening CSV file for writing!\n");
        return;
    }


    fprintf(csvFile, "%d\n", laundryNo);

    fclose(csvFile);
}

void laundry_receive() {
    int laundry_no;
    printf("Enter the laundry number to receive: ");
    scanf("%d", &laundry_no);

    writeLaundryToCSV("laundry.csv", laundry_no);

    printf("Laundry with number %d received successfully.\n", laundry_no);


    system("cls");
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




