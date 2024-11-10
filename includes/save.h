#ifndef SAVE_H
#define SAVE_H
#include <stdio.h>
/*
    --name <account_name>
    --help | -h
*/
void save_to_file(FILE* file, const char* filename, char* password, char* account_name);
void list(const char* filename);
void s_help();
#endif