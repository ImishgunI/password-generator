#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/generator.h"
#include "../includes/save.h"

void save_to_file_test() {
    int length = 10;
    char* password = NULL;
    password = generate(length, password, 3, "-s", "-n", "-uc");
    FILE* acc_file = NULL;
    const char* filename = "../account.txt";
    char* account = "mishgun";
    save_to_file(acc_file, filename, password, account);
    list(filename);
}

int main() {
    save_to_file_test();
    s_help();
}