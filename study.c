#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "admin.h"

#define MAX_OCCUPANCY 100
#define ROWS 10
#define COLUMNS 10

void draw_study_room(int occupied[]) {
    printf("%20s", " ");
    for (int i = 0; i < ROWS; i++) {
        printf("Table %d: ", i + 1);
        for (int j = 0; j < COLUMNS; j++) {
            int seat_number = i * COLUMNS + j;
            if (occupied[seat_number]) {
                printf("[X] "); 
            } else {
                printf("[%d] ", seat_number); 
            }
        }
        printf("\n%20s", " ");
    }
}

void update_seat_status(int occupied[], int seat_number, int status) {
    occupied[seat_number] = status;
    FILE* fp = fopen("study.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < MAX_OCCUPANCY; i++) {
        fprintf(fp, "%d", occupied[i]);
    }
    fclose(fp);
}

void study() {
    FILE* fp;
    int occupied[MAX_OCCUPANCY] = {0};
    char c;

    fp = fopen("study.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < MAX_OCCUPANCY; i++) {
        fscanf(fp, " %c", &c);
        occupied[i] = c - '0';
    }
    fclose(fp);

    draw_border(312, '-');
    printf("\n");
    center_print("Female Halls of Residence");
    printf("\n");
    draw_border(312, '-');
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option:");
    center_print("Show Occupancy (#1)");
    center_print("Update Occupancy (#2)");
    center_print("Go back to student Menu (#3)");
    int what_to_do;

error:
    scanf(" %c", &what_to_do);
    switch (what_to_do) {
        case '1':
            system("cls");
            draw_border(312, '-');
            printf("\n");
            center_print("Female Halls of Residence");
            printf("\n");
            draw_border(312, '-');
            printf("\n\n\n\n\n\n\n\n\n\n");
            draw_study_room(occupied);
            printf("GO Back (B)\n");
            char option;
            scanf(" %c", &option);

            if (option == 'B' || option == 'b') {
                system("cls");
                study();
            }
            break;
        case '2':
            system("cls");
            draw_border(312, '-');
            printf("\n");
            center_print("Female Halls of Residence");
            printf("\n");
            draw_border(312, '-');
            printf("\n\n\n\n\n\n\n\n\n\n");
            draw_study_room(occupied);

            int seat_number;
            do {
                printf("Enter the seat number you want to update (0-99): ");
                scanf("%d", &seat_number);

                if (seat_number < 0 || seat_number >= MAX_OCCUPANCY) {
                    printf("Invalid seat number. Please try again.\n");
                }
            } while (seat_number < 0 || seat_number >= MAX_OCCUPANCY);

            printf("Enter 'in' to occupy or 'out' to vacate the seat: ");
            char action[4];
            scanf("%s", action);

            if (strcmp(action, "in") == 0) {
                if (occupied[seat_number]) {
                    printf("Seat %d is already occupied.\n", seat_number);
                } else {
                    update_seat_status(occupied, seat_number, 1);
                    printf("Seat %d status updated to occupied.\n", seat_number);
                }
            } else if (strcmp(action, "out") == 0) {
                if (!occupied[seat_number]) {
                    printf("Seat %d is already unoccupied.\n", seat_number);
                } else {
                    update_seat_status(occupied, seat_number, 0);
                    printf("Seat %d status updated to unoccupied.\n", seat_number);
                }
            } else {
                printf("Invalid action. Please enter 'in' or 'out'.\n");
            }

            printf("GO Back (B)\n");
            char option2;
            scanf(" %c", &option2);

            if (option2 == 'B' || option2 == 'b') {
                system("cls");
                study();
            }
            break;
        case '3':
            system("cls");
            student_menu();
            break;
        default:
            printf("Invalid Input. Please try again\n");
            goto error;
    }
}

