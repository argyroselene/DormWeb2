#include <stdio.h>

int notice_check() {
    FILE *not;

    not = fopen("notice.txt", "r");

    if ( not== NULL) {
        printf("Error opening file.\n");
        home();
    }

    char line[100];
    while (fgets(line, sizeof(line), not)) {
        printf("%s", line);
    }

    fclose(not);
    center_print("Press (B) or (b) to go back");
    center_print("Press any key to continue");

    char option2;
        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            login_student();
        }
    else{
    char temp;
    fflush(stdin);
    system("cls");
    home();
    }

}


