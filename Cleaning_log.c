#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

char ch;

int CleaningAlreadyDone(char *filename, char *RoomNumber) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char room[MAX_LENGTH];
        sscanf(line, "%[^:]", room);

        char *ptr = room;
        while (*ptr == ' ' || *ptr == '\t')
            ptr++;
        for (int i = strlen(ptr) - 1; i >= 0 && (ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\n'); i--)
            ptr[i] = '\0';

        if (strcmp(room, RoomNumber) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void updateCleaningStatus(char *filename, char *RoomNumber) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s: Clean\n", RoomNumber);
    printf("\n");
    center_print("Cleaning successfully updated.\n");
    fclose(file);
    
    do {
        printf("Go back (b)");
        scanf(" %c",&ch);
        system("cls");
        if(tolower(ch) != 'b')
            printf("Invalid input. Please enter 'b' to go back.\n");
    } while (tolower(ch) != 'b');

    if(ch=='b'||ch=='B'){
        cleaning();
    }
}

void addComment(char *filename, char *RoomNumber, char *comment) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Room Number: %s\nComment: %s\n\n", RoomNumber, comment);
    printf("Comment successfully added.\n");
    fclose(file);
    
    do {
        printf("Go back (b)");
        scanf(" %c",&ch);
        system("cls");
        if(tolower(ch) != 'b')
            printf("Invalid input. Please enter 'b' to go back.\n");
    } while (tolower(ch) != 'b');

    if(ch=='b'||ch=='B'){
        cleaning();
    }
}

void cleaning() {
    char filename[] = "cleaning_records.txt";
    char comment_filename[] = "cleaning_comment.txt";

    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Update Cleaning Status (#1)\n");
    center_print("Add Comment (#2)\n");
    center_print("Back to student menu (#3)");
    char choice;
    scanf(" %c", &choice);

    if (choice == '1') {
        char RoomNumber[MAX_LENGTH];
        printf("%90s","Enter room number: ");
        scanf("%s", RoomNumber);

        if (CleaningAlreadyDone(filename, RoomNumber) == 1) {
            center_print("Cleaning has already been done.\n");
            
            do {
                printf("Go back (b)");
                scanf(" %c",&ch);
                system("cls");
                if(tolower(ch) != 'b')
                    printf("Invalid input. Please enter 'b' to go back.\n");
            } while (tolower(ch) != 'b');

            if(ch=='b'||ch=='B'){
                cleaning();
            }

        } else if (CleaningAlreadyDone(filename, RoomNumber) == -1) {
            printf("Error: Unable to check cleaning status.\n");
            
            do {
                printf("Go back (b)");
                scanf(" %c",&ch);
                system("cls");
                if(tolower(ch) != 'b')
                    printf("Invalid input. Please enter 'b' to go back.\n");
            } while (tolower(ch) != 'b');

            if(ch=='b'||ch=='B'){
                cleaning();
            }
        } else {
            updateCleaningStatus(filename, RoomNumber);
        }
    } else if (choice == '2') {
        char RoomNumber[MAX_LENGTH];
        printf("%90s","Enter room number: ");
        scanf("%s", RoomNumber);

        char comment[MAX_LENGTH];
        printf("%90s","Enter comment: ");
        scanf(" %[^\n]", comment);

        addComment(comment_filename, RoomNumber, comment);
    }
    else if(choice=='3'){
        system("cls");
        student_menu();
    }
    else{
        system("cls");
        printf("Invalid input,try again");
        cleaning();
    }
}

