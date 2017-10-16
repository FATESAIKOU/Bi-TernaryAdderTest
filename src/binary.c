#ifndef BINARY_ADD_INCLUDED
#define BINARY_ADD_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define B_FALSE 0
#define B_TRUE 1

inline uint8_t B_AND(uint8_t a, uint8_t b) {
    if (a == B_TRUE && b == B_TRUE) {
        return B_TRUE;
    } else {
        return B_FALSE;
    }
}

inline uint8_t B_OR(uint8_t a, uint8_t b) {
    if (a == B_TRUE || b == B_TRUE) {
        return B_TRUE;
    } else {
        return B_FALSE;
    }
}

inline uint8_t B_XOR(uint8_t a, uint8_t b) {
    if (a ^ b) {
        return B_TRUE;
    } else {
        return B_FALSE;
    }
}

inline uint8_t B_NOT(uint8_t a) {
    if (a == B_TRUE) {
        return B_FALSE;
    } else {
        return B_TRUE;
    }
}

uint8_t B_CONS(uint8_t a, uint8_t b, uint8_t c) {
    if (B_XOR(B_XOR(a, b), c) == B_TRUE) {
        return B_TRUE;
    } else {
        return B_FALSE;
    }
}

uint8_t B_CARRY(uint8_t a, uint8_t b, uint8_t c) {
    if (B_OR(B_AND(a, b), B_AND(B_XOR(a, b), c)) == B_TRUE) {
        return B_TRUE;
    } else {
        return B_FALSE;
    }
}

uint8_t* B_ADD(uint8_t *a, uint8_t *b, int len) {
    int i;

    uint8_t bit_a, bit_b, bit_c;
    uint8_t* result = (uint8_t*) malloc(sizeof(uint8_t) * len);
    for (bit_c = 0, i = 0; i < len; ++ i) {
        bit_a = a[i];
        bit_b = b[i];

        bit_c = B_CARRY(bit_a, bit_b, bit_c);
        result[i] = B_CONS(bit_a, bit_b, bit_c);
    }

    return result;
}

uint8_t* fromDec(int a, int len) {
    uint8_t* result = (uint8_t*) malloc(sizeof(uint8_t) * len);

    int i;
    for (i = 0; i < len; ++ i) {
        result[i] = (a & 1 << i) >> i;
    }

    return result;
}

int toDec(uint8_t* a, int len) {
    int sum = 0;
    int i;

    for (i = 0; i < len; ++ i) {
        sum |= a[i] << i;
    }

    return sum;
}

void showBinary(uint8_t* a, int len) {
    int i;
    printf("\t");
    for (i = 1; i <= len; ++ i) {
        printf("%d", a[len - i]);
    }
    printf("\n");
}

#endif
