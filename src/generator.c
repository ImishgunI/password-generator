#include "../includes/generator.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getLength(char* length) {
    return atoi(length);
}

char* generate(int length, int amount_of_params, ...) {
    srand(time(NULL));
    char password[length];
    char randomSymbol = 0;
    char random = 0;
    char* letters = "abcdefghijklmnopqrstuvwxyz";          
    char* symbols = "~!@#$%^&*()[]{}";
    char* numbers = "1234567890";
    char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";        
    if(amount_of_params > 0){
        va_list flags;
        va_start(flags, amount_of_params);
        char* params[amount_of_params];
        for(int i = 0; amount_of_params; ++i) {
            params[i] = va_arg(flags, char*);
        }
        if(amount_of_params == 1) {
            if(strcmp(params[1], "--symbols") == 0 || strcmp(params[1], "-s") == 0) {
                for(int i = 0; i < length; ++i) {
                    random = rand() % strlen(letters);
                    randomSymbol = rand() % strlen(symbols);
                    if(random > randomSymbol) {
                        password[i] = letters[random];
                    } else {
                        password[i] = symbols[randomSymbol];
                    }
                }
            }
        }
    } else {
        for(int i = 0; i < length; ++i) {
            random = rand() % strlen(letters);
            password[i] += letters[random];
        }
    }
    return password;
}