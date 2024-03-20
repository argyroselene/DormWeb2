#include <stdio.h>
#include <string.h>
#include"search_student.h"

void search_student(){

    FILE *dash;
    struct Student student;


    dash = fopen("database.txt", "r");
    if (dash == NULL) {
        printf("Error: Unable to open the file.\n");
    }


    char input_id[20];
    printf("Enter student ID: ");
    scanf("%s", input_id);


    int found = 0;
    while (fscanf(dash, "%[^,],%[^,],%d,%[^,],%[^,],%[^\n]", student.name, student.id, &student.room, student.department, student.payment_status, student.contact_number) != EOF) {
        if (strcmp(student.id, input_id) == 0) {
            found = 1;
            break;
        }
    }


    if (found) {
        printf("\nStudent Information:\n");
        printf("Name: %s\n", student.name);
        printf("ID: %s\n", student.id);
        printf("Room: %d\n", student.room);
        printf("Department: %s\n", student.department);
        printf("Payment Status: %s\n", student.payment_status);
        printf("Contact Number: %s\n", student.contact_number);
    } else {
        printf("Error: Student with ID '%s' not found.\n", input_id);
    }

    
    fclose(dash);
}

