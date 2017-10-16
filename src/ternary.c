#ifndef TERNARY_ADD_INCLUDED
#define TERNARY_ADD_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define T_FALSE 0
#define T_UNK 1
#define T_TRUE 2

typedef uint8_t trit;

inline trit T_MUX(trit a, trit b) {
    // Define basic MUX here!!
}

trit tritAt(int16_t a, int16_t idx) {
    return (trit)((a & (3 << (idx * 2))) >> (idx * 2));
}

uint16_t decToTer(int16_t a) {
    // Convert Here!!
}

char* showTernary(uint16_t a) {
    int i;
    
    char *trit_str = (char*) malloc(sizeof(char) * 8);
    for (i = 7; i >= 0; -- i) {
        switch (tritAt(a, i)) {
            case 0: trit_str[7 - i] = 'T'; break;
            case 1: trit_str[7 - i] = '0'; break;
            case 2: trit_str[7 - i] = '1'; break;
        }
    }

    return trit_str;
}


#endif
