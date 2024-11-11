#include "../includes/search.h"


void s_test() {
    const char* acc = "mishgun";
    const char* fl = "../passwords.txt";
    search(acc, fl);
}

int main() {
    s_test();
}