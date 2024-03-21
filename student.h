#pragma once

void draw_border(int length,char symbol);
void print_centre_wnl(char *s);
void login_student();
unsigned long encryption(char* passcode);
struct account{
    char username[101];
    char passcode[101];
    };
