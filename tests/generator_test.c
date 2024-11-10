#include "../includes/generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generator_test() {
    char* password = NULL;
    password = generate(10, password, 0, "");
    for (int i = 0; i < 10; ++i) {
        printf("%c", password[i]);
    }
    free(password);
}

void help_test() { help(); }

int main() {
    generator_test();
    printf("\n\n");
    help();
}