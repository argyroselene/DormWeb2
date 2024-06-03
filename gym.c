#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EQUIPMENTS 5
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[30];
    int occupied;
} Equipment;

void read_gym_equipment_data(Equipment equipments[]) {
    FILE *csv_file = fopen("equipments.csv", "r");
    FILE *txt_file = fopen("gym_equipment.txt", "w");
    char line[MAX_LINE_LENGTH];
    int i = 0;
    char name[30];
    int occupied = 0;
    while (fgets(line, sizeof(line), csv_file) != NULL && i < MAX_EQUIPMENTS) {
        if (sscanf(line, "%[^,],%d", name, &occupied) == 2) {
            strcpy(equipments[i].name, name);
            equipments[i].occupied = occupied;
            fprintf(txt_file, "%s %d\n", name, occupied);
            i++;
        }
    }

    fclose(txt_file);
    fclose(csv_file);
}

void read_gym_equipment_data_from_text_file(Equipment equipments[]) {
    FILE *txt_file = fopen("gym_equipment.txt", "r");
    if (txt_file == NULL) {
        printf("Error opening text file for reading.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, sizeof(line), txt_file) != NULL && i < MAX_EQUIPMENTS) {
        sscanf(line, "%s %d", equipments[i].name, &equipments[i].occupied);
        i++;
    }

    fclose(txt_file);
}

void update_csv_file(Equipment equipments[]) {
    FILE *csv_file = fopen("equipments.csv", "w");

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
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_EQUIPMENTS) {
            printf("Invalid choice. Please try again.\n");
        } else {
            break;
        }
    }

    int index = choice - 1;

    printf("1. Occupy\n2. Unoccupy\n");
    int action;
    while (1) {
        printf("Enter the action you want to perform (1 to Occupy, 2 to Unoccupy): ");
        scanf("%d", &action);

        if (action != 1 && action != 2) {
            printf("Invalid action. Please try again.\n");
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

    FILE *txt_file = fopen("gym_equipment.txt", "w");
    for (int i = 0; i < MAX_EQUIPMENTS; i++) {
        fprintf(txt_file, "%s %d\n", equipments[i].name, equipments[i].occupied);
    }
    fclose(txt_file);

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
    FILE *txt_file = fopen("gym_equipment.txt", "r");
    if (txt_file == NULL) {
        printf("Error opening text file for reading.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Unoccupied Gym Equipments:\n");
    while (fgets(line, sizeof(line), txt_file) != NULL) {
        char name[30];
        int occupied;
        sscanf(line, "%s %d", name, &occupied);
        if (occupied == 0) {
            printf("%s\n", name);
        }
    }

    fclose(txt_file);
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
    read_gym_equipment_data_from_text_file(equipments);

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

