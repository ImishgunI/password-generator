#ifndef BUFFER_FILE_H
#define BUFFER_FILE_H

#include <stdio.h>

void save_password_to_buffer_file(char* password, FILE* buffer, const char* filename);
int remove_buffer_file(const char* filename);
char* read_from_file(int length, char* password, const char* filename);
#endif // BUFFER_FILE_H