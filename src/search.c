#include "../includes/search.h"

#include <stdio.h>
#include <string.h>

void search(const char* account_name, const char* filename) {
    FILE* file = fopen(filename, "r");
    char name[100][256];
    int i = 0;
    while(i < 100 && (fgets(name[i], 256, file) != NULL)) {
        name[i][strcspn(name[i], "\n")] = '\0';
        ++i;
    }

    for(int j = 0; j < i; ++j) {
        char* acc = strstr(name[j], account_name);
        if(acc != NULL) {
            printf("%s\n", name[j]);
        }
    }
    fclose(file);
}