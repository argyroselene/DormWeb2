#include <stdio.h>

int menu() {
    FILE *menu;

    menu = fopen("food_menu.txt", "r");

    if (menu == NULL) {
        printf("Error opening file.\n");
        home();
    }

    char line[100];
    while (fgets(line, sizeof(line), menu)) {
        printf("%s", line);
    }

    fclose(menu);
}
