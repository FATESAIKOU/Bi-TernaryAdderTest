#ifndef TERNARY_ADD_INCLUDED
#define TERNARY_ADD_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define T_FALSE 0
#define T_UNK 1
#define T_TRUE 2

typedef uint8_t trit;

inline trit T_MUX(trit sel, trit inN, trit inO, trit inP) {
    if (sel == T_FALSE) {
        return inN;
    } else if (sel == T_UNK) {
        return inO;
    } else if (sel == T_TRUE) {
        return inP;
    } else {
        exit(-1);
    }
}

trit T_HA(trit a, trit b) {
    trit pinN = T_MUX(a, T_TRUE, T_FALSE, T_UNK);
    trit pinP = T_MUX(a, T_UNK, T_TRUE, T_FALSE);
    trit sum = T_MUX(b, pinN, a, pinP);

    return sum;
}

trit T_CON(trit a, trit b) {
    trit pinN = T_MUX(a, T_FALSE, T_UNK, T_UNK);
    trit pinP = T_MUX(a, T_UNK, T_UNK, T_TRUE);
    trit con = T_MUX(b, pinN, T_UNK, pinP);

    return con;
}

trit T_FA(trit a, trit b, trit cin) {
    return T_HA(T_HA(a, b), cin);
}

trit T_OVF(trit a, trit b, trit cin) {
    return T_CON(T_CON(a, b), cin);
}

trit tritAt(int16_t a, int16_t idx) {
    return (trit)((a & (3 << (idx * 2))) >> (idx * 2));
}

uint16_t decToTer(int16_t a) {
    int i;
    int inv = 1;

    if (a < 0) {
        a *= inv = -1;
    }

    uint16_t res = 0, carry = 0, remainder;
    for (i = 0; i < 8; ++ i) {
        remainder = a % 3;

        if (remainder + carry == 3) {
            carry = 1;
            res |= T_UNK << (i * 2);
        } else if (remainder + carry == 2) {
            carry = 1;
            res |= ((inv == 1) ? T_FALSE:T_TRUE) << (i * 2);
        } else if (remainder + carry == 1) {
            carry = 0;
            res |= ((inv == 1) ? T_TRUE:T_FALSE) << (i * 2);
        } else if (remainder + carry == 0) {
            carry = 0;
            res |= T_UNK << (i * 2);
        } else {
            exit(1);
        }

        a /= 3;
    }

    return res;
}

int16_t terToDec(uint16_t a) {
    int i, fac;
    int16_t res = 0;
    
    for (i = 0, fac = 1; i < 8; ++ i, fac *= 3) {
        switch (tritAt(a, i)) {
            case T_FALSE: res += -1 * fac; break;
            case T_TRUE:  res += 1 * fac; break;
        }
    }

    return res;
}

char* showTernary(uint16_t a) {
    int i;
    
    char *trit_str = (char*) malloc(sizeof(char) * 8);
    for (i = 0; i < 8; ++ i) {
        switch (tritAt(a, i)) {
            case T_FALSE: trit_str[7 - i] = 'T'; break;
            case T_UNK:   trit_str[7 - i] = '0'; break;
            case T_TRUE:  trit_str[7 - i] = '1'; break;
        }
    }

    return trit_str;
}


#endif
