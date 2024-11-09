#include "../includes/buffer_file.h"
#include "../includes/generator.h"

#include <stdio.h>
#include <stdlib.h>

void buffer_test() {
    char* password = NULL;
    int length = 10;
    password = generate(10, password, 3, "-s", "-n", "-uc");
    printf("%s\n", password);
    const char* filename = "../buffer.txt";
    FILE* buffer = NULL;
    save_password_to_buffer_file(password, buffer, filename);
    free(password);
    char* passwrd = NULL;
    passwrd = read_from_file(length, passwrd, filename);
    printf("%s\n", passwrd);
    free(passwrd);
    remove_buffer_file(filename);
}

int main() {
    buffer_test();
}