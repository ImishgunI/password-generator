#ifndef GENERATOR_H
#define GENERATOR_H

/*
    Список флагов для generate:
    --length <number> || -l <numbers> обязательный
    --symbols || -s
    --numbers  || -n
    --uppercase ||-uc
    --help || -h
    Если 0 флагов кроме длины -> случайный пароль
*/
void help();
char* generate(int length, char* password, int amount_of_params, ...);

#endif  // GENERATOR_H