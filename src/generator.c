#include "../includes/generator.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int getLength(char* length) {
    return atoi(length);
}

char* generate(int length, int amount_of_params, ...) {
    va_list flags;
    va_start(flags, amount_of_params);
    char* params[amount_of_params];
    for(int i = 0; amount_of_params; ++i) {
        params[i] = va_arg(flags, char*);
    }
    
}