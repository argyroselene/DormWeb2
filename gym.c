#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQUIPMENTS 5
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[30];
    int occupied;
} Equipment;

void read_gym_equipment_data(Equipment equipments[]) {
    FILE *csv_file = fopen("gym_equipment.csv", "r");
    if (csv_file == NULL) {
        perror("Error opening CSV file for reading");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, sizeof(line), csv_file) != NULL && i < MAX_EQUIPMENTS) {
        if (sscanf(line, "%[^,],%d", equipments[i].name, &equipments[i].occupied) == 2) {
            i++;
        }
    }

    fclose(csv_file);
}

void update_csv_file(Equipment equipments[]) {
    FILE *csv_file = fopen("gym_equipment.csv", "w");
    if (csv_file == NULL) {
        perror("Error opening CSV file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_EQUIPMENTS; i++) {
        fprintf(csv_file, "%s,%d\n", equipments[i].name, equipments[i].occupied);
    }
    fclose(csv_file);
}

void update_gym_equipment_status(Equipment equipments[]) {
    printf("Available Equipments to update:\n");
    for (int i = 0; i < MAX_EQUIPMENTS; i++) {
        printf("%d. %s (Status: %s)\n", i + 1, equipments[i].name, equipments[i].occupied ? "Occupied" : "Unoccupied");
    }

    int choice;
    while (1) {
        printf("Enter the number of the equipment you want to update: ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > MAX_EQUIPMENTS) {
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    }

    int index = choice - 1;

    printf("1. Occupy\n2. Unoccupy\n");
    int action;
    while (1) {
        printf("Enter the action you want to perform (1 to Occupy, 2 to Unoccupy): ");
        if (scanf("%d", &action) != 1 || (action != 1 && action != 2)) {
            printf("Invalid action. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    }

    if (action == 1) {
        if (equipments[index].occupied == 1) {
            printf("%s is already occupied.\n", equipments[index].name);
        } else {
            equipments[index].occupied = 1;
            printf("%s status updated to occupied.\n", equipments[index].name);
        }
    } else if (action == 2) {
        if (equipments[index].occupied == 0) {
            printf("%s is already unoccupied.\n", equipments[index].name);
        } else {
            equipments[index].occupied = 0;
            printf("%s status updated to unoccupied.\n", equipments[index].name);
        }
    }

    update_csv_file(equipments);

    printf("\nPress 'b' to go back.\n");

    char ch;
    while (1) {
        scanf(" %c", &ch);
        if (ch == 'b' || ch == 'B') {
            break;
        } else {
            printf("Invalid input. Please press 'b' to go back.\n");
        }
    }
}

void show_unoccupied_gym_equipment() {
    Equipment equipments[MAX_EQUIPMENTS];
    read_gym_equipment_data(equipments);

    printf("Unoccupied Gym Equipments:\n");
    for (int i = 0; i < MAX_EQUIPMENTS; i++) {
        if (!equipments[i].occupied) {
            printf("%s\n", equipments[i].name);
        }
    }

    printf("\nPress 'b' to go back.\n");

    char ch;
    while (1) {
        scanf(" %c", &ch);
        if (ch == 'b' || ch == 'B') {
            break;
        } else {
            printf("Invalid input. Please press 'b' to go back.\n");
        }
    }
}

void gym_menu(Equipment equipments[]) {
    system("cls");
    draw_border(312, '-');
    printf("\n");
    center_print("Female Halls of Residence");
    center_print("TV room and Gym");
    printf("\n");
    draw_border(312, '-');
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("Gym Menu:\n");
    printf("1. Show Unoccupied Equipments\n");
    printf("2. Update Equipment Occupancy\n");
    printf("3. Go Back to Student Menu\n");
}

void gym() {
    Equipment equipments[MAX_EQUIPMENTS];
    read_gym_equipment_data(equipments);

    while (1) {
        gym_menu(equipments);
        printf("Enter your choice: ");
        char choice;
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                show_unoccupied_gym_equipment();
                break;
            case '2':
                update_gym_equipment_status(equipments);
                break;
            case '3':
                system("cls");
                student_menu();
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

