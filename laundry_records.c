#include <stdio.h>
#include"laundry.h"

int laundry_records() {
    FILE *laundry;

    laundry = fopen("laundry.txt", "r");

    if (laundry == NULL) {
        printf("Error opening file.\n");
        home();
    }

    char line[100];
    while (fgets(line, sizeof(line), laundry)) {
        printf("%s", line);
    }

    fclose(laundry);
    center_print("Press (B) or (b) to go back");
    center_print("Press any key to continue");

    char option2;;
        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            laundry_main();
        }
    else{
            char temp;
    fflush(stdin);
    system("cls");
    home();
    }
}

