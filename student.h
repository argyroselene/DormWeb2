#pragma once

void draw_border(int length,char symbol);
void print_centre_wnl(char *s);
void login_student();
void study();
unsigned long encryption(char* passcode);
struct account{
    char name [120];
    char id[120];
    char username[101];
    unsigned long passcode;
    };
