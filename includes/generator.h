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

int getLength(char* length);

char* generate(int length, int amount_of_params, ...);

#endif // GENERATOR_H