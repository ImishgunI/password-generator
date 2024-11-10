#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/generator.h"
#include "../includes/buffer_file.h"
#include "../includes/save.h"

int main(int argc, char* argv[]) {
    int length = 0;
    char symbols[11];
    char numbers[11];
    char uc[15];
    memset(symbols, 0, 11);
    memset(numbers, 0, 11);
    memset(uc, 0, 15);
    char account_name[100];
    memset(account_name, 0, 100);
    const char* buffer = "../buffer.txt";
    const char* passwordFile = "../passwords.txt";
    if(argc < 2) {
        perror("No enougth arguments\n");
        exit(1);
    }
    if(strcmp(argv[1], "generate") == 0 && (strcmp(argv[2], "--help") == 0 || strcmp(argv[2], "-h") == 0)) {
        help();
    } else if(strcmp(argv[1], "save") == 0 && (strcmp(argv[2], "--help") == 0 || strcmp(argv[2], "-h") == 0)) {
        s_help();
    }
    else if(strcmp(argv[1], "generate") == 0 && (strcmp(argv[2], "--length") == 0 || strcmp(argv[2], "-l") == 0)) {
        length = atoi(argv[3]);
        if(length < 6) {
            perror("Length must be > 6\n");
            exit(1);
        }
        int amount_of_params = 0;
        for(int i = 0; i < argc; ++i) {
            if(strcmp(argv[i], "--symbols") == 0 || strcmp(argv[i], "-s") == 0) {
                memcpy(symbols, argv[i], strlen(argv[i]));
                amount_of_params++;
            } else if(strcmp(argv[i], "--numbers") == 0 || strcmp(argv[i], "-n") == 0) {
                memcpy(numbers, argv[i], strlen(argv[i]));
                amount_of_params++;
            } else if(strcmp(argv[i], "--uppercase") == 0 || strcmp(argv[i], "-uc") == 0) {
                memcpy(uc, argv[i], strlen(argv[i]));
                amount_of_params++;
            }
        }
        char* password = NULL;
        password = generate(length, password, amount_of_params, symbols, numbers, uc);
        FILE* buffer_file = NULL;
        save_password_to_buffer_file(password, buffer_file, buffer);
        free(password);
    }
    else if(strcmp(argv[1], "save") == 0 && strcmp(argv[2], "--name") == 0) {
        memcpy(account_name, argv[3], strlen(argv[3]));
        FILE* password_file = NULL;
        char* password = NULL;
        int len = getLength(buffer);
        password = read_from_file(len, password, buffer);
        save_to_file(password_file, passwordFile, password, account_name);
        free(password);
        remove_buffer_file(buffer);
    } else if(strcmp(argv[1], "list") == 0) {
        list(passwordFile);
    } else {
        perror("Unknown command\n");
        exit(1);
    }
}