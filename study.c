#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include"admin.h"

void study()
{
    FILE* fp;
    int occupied;
    fp=fopen("study.txt", "r");
    fscanf(fp,"%d",&occupied);
    fclose(fp);
    printf("\n\n\n\n\n\n\n\n\n\n");
    center_print("Please choose an option:");
    center_print("Show Occupancy(#1)");
    center_print("Update Occupancy(#2)");
    int what_to_do;

error:
    scanf("%d",&what_to_do);
    switch (what_to_do)
    {
    case 1:
        system("cls");
        if(occupied==100) center_print("Study room is currently fully occupied.");
        else printf("Unoccupied -> %d\n",100-occupied);
        printf("GO Back(B)\n");
        char option;
        scanf(" %c",&option);

        if(option == 'B' || option == 'b')

        {
            system("cls");
            study();
        }
        break;
    case 2:
        system("cls");
        printf("Are you entering or leaving the study room? (Enter 'in' or 'out'): ");
        char action[4];
        scanf("%s", action);

        if (strcmp(action, "in") == 0)
        {
            if (occupied != 100)
            {
                fp = fopen("study.txt", "w");
                if (fp != NULL)
                {
                    occupied++;
                    fprintf(fp, "%d", occupied);
                    printf("Unoccupied -> %d\n",100-occupied);
                    printf("GO Back(B)\n");
                    fclose(fp);
                }
                else
                {
                    printf("Error opening file for writing.\n");
                }
            }
            else
            {
                center_print("Study room is currently fully occupied.");
            }
        }
        else if (strcmp(action, "out") == 0)
        {
            if (occupied > 0)
            {
                fp = fopen("study.txt", "w");
                if (fp != NULL)
                {
                    occupied--;
                    fprintf(fp, "%d", occupied);
                    printf("Unoccupied -> %d\n",100-occupied);
                    printf("GO Back(B)\n");
                    fclose(fp);
                }
                else
                {
                    printf("Error opening file for writing.\n");
                }
            }
            else
            {
                center_print("Study room is currently empty.");
            }
        }
        else
        {
            printf("Invalid action. Please enter 'in' or 'out'.\n");
        }

        char option2;;
        scanf(" %c",&option2);

        if(option2 == 'B' || option2 == 'b')

        {
            system("cls");
            study();
        }
        break;
    default:
        printf("Invalid Input. Please try again\n");
        break;
        goto error;
    }
}
