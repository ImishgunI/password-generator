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