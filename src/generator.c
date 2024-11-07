#include "../includes/generator.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getLength(char* length) {
    return atoi(length);
}

char* generate(int length, char* password, int amount_of_params, ...) {
    srand(time(NULL));
    password = malloc(length + 1 * sizeof(char));
    char allSymbols[100];
    memset(allSymbols, 0, 100);
    int random = 0;
    char* letters = "abcdefghijklmnopqrstuvwxyz";          
    char* symbols = "~!@#$%%^&*()[]{}";
    char* numbers = "1234567890";
    char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    strcat(allSymbols, letters);       
    if(amount_of_params > 0){
        va_list flags;
        va_start(flags, amount_of_params);
        char* params[amount_of_params];
        for(int i = 0; i < amount_of_params; ++i) {
            params[i] = va_arg(flags, char*);
            if(strcmp(params[i], "--symbols") == 0 || strcmp(params[i], "-s") == 0) {
                strcat(allSymbols, symbols);
            } else if(strcmp(params[i], "--numbers") == 0 || strcmp(params[i], "-n") == 0) {
                strcat(allSymbols, numbers);
            } else if(strcmp(params[i], "--uppercase") == 0 || strcmp(params[i], "-uc") == 0) {
                strcat(allSymbols, uppercase);
            }
        }
        int size = strlen(allSymbols);
        for(int i = 0; i < length; ++i) {
            password[i] = allSymbols[rand() % size];
        }
    } else {
        for(int i = 0; i < length; ++i) {
            random = rand() % strlen(allSymbols);
            password[i] = allSymbols[random];
        }
    }
    password[length - 1] = '\0';    
    return password;
}

void help() {
    printf("Parameters for generate:\n");
    printf("generate --length <number> --symbols --numbers --uppercase\n\n");
    printf("--length <number> | -l This parameter must use, it's first parametr after generate command,\n\
    \t\t       length of password must be minimum 6 or bigger.\n\n");
    printf("--symbols | -s         This not mendotary parameter. Add symbols ~!@#$%%^&*()[]{} to password\n\n");
    printf("--numbers | -n         Not mendotary parameter. Add numbers from 0 to 9 to password\n\n");
    printf("--uppercase | -uc      Not mendotary parameter. Add uppercase letters to password\n\n");
    printf("--help | -h            Print helpful information\n\n");
}