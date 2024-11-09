#include "../includes/save.h"

#include <stdio.h>

void save_to_file(FILE* file, const char* filename, char* password, char* account_name) {
    file = fopen(filename, "a+");
    fprintf(file, "%s - %s\n", account_name, password);
    fclose(file);
}

void list(const char* filename) {
    FILE* list = fopen(filename, "r");
    char buffer[256];
    if(!feof(list)) {
        while(fgets(buffer, 256, list) != NULL) {
            printf("%s\n", buffer);
        }
    }
    fclose(list);
}