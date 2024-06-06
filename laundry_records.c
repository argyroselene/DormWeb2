#include <stdio.h>
#include "laundry.h"

int laundry_records() {
    FILE *laundry;

    laundry = fopen("laundry.csv", "r");

    if (laundry == NULL) {
        printf("Error opening file.\n");
        home();
    }

    printf("\n%-12s%-12s%-12s%-18s%-18s\n", "Laundry No", "Name", "Room", "Bedsheet Q", "Pillow Cover Q");
    printf("--------------------------------------------------------------\n");

    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), laundry)) {
        if (count == 0) { // Skip the header line
            count++;
            continue;
        }

        int laundryNo;
        char name[100];
        int room;
        int bedsheetQty, pillowCoverQty;

        sscanf(line, "%d,%[^,],%d,%d,%d", &laundryNo, name, &room, &bedsheetQty, &pillowCoverQty);

        printf("%-12d%-12s%-12d%-18d%-18d\n", laundryNo, name, room, bedsheetQty, pillowCoverQty);
        count++;
    }

    fclose(laundry);

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



