#include "../includes/buffer_file.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void save_password_to_buffer_file(char* password, FILE* buffer, const char* filename) {
    buffer = fopen(filename, "a+");
    if(buffer == NULL) {
        perror("can not open file: No such file or directory\n");
        exit(0);
    }
    int len = strlen(password);
    for(int i = 0; i < len; ++i) {
        fputc(password[i], buffer);
    }
    fclose(buffer);
}

int remove_buffer_file(const char* filename) {
    return remove(filename);
}

int getLength(const char* filename) {
    FILE* file = fopen(filename, "r");
    int length = 0;
    while(fgetc(file) != EOF) {
        ++length;
    }
    fclose(file);
    return length;
}

char* read_from_file(int length, char* password, const char* filename) {
    password = malloc(length + 1 * sizeof(char));
    memset(password, 0, length + 1);
    FILE* file = fopen(filename, "r");
    char c = 0;
    int i = 0;
    while(!feof(file) && i < length) {
        c = fgetc(file);
        password[i] = c;
        ++i;
    }
    password[i + 1] = '\0';
    fclose(file);
    return password;
}