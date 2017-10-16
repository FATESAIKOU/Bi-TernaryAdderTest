#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binary.c"
#include "ternary.c"


int main() {
    int16_t a = 1, b = 1;
    printf("Binary:\n");
    printf("a: %s\n", showBinary(a));
    printf("b: %s\n", showBinary(b));
    printf("a+b: %d\n", binaryAdd(a, b));
    printf("a+b: %s\n", showBinary(binaryAdd(a, b)));

    printf("Ternary:\n");
    printf("a: %s\n", showTernary(a));
    printf("b: %s\n", showTernary(b));

    return 0;
}
