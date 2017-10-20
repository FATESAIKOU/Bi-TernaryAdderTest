#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binary.c"
#include "ternary.c"


int main() {
    int16_t a = 1, b = -1, i;
    printf("Binary:\n");
    printf("a: %s\n", showBinary(a));
    printf("b: %s\n", showBinary(b));
    printf("a+b: %d\n", binaryAdd(a, b));
    printf("a+b: %s\n", showBinary(binaryAdd(a, b)));

    printf("Ternary:\n");
    printf("a: %s\n", showTernary(decToTer(a)));
    printf("b: %s\n", showTernary(decToTer(b)));

    for (i = 1; i < 3281; ++ i) {
        //printf("+%d: %s - %d\n", i, showTernary(decToTer(i)), terToDec(decToTer(i)));
        //printf("%d: %s - %d\n", -i, showTernary(decToTer(-i)), terToDec(decToTer(-i)));
        printf("%d + %d = %d\n", i, -i - 1, terToDec(ternaryAdd(decToTer(i), decToTer(-i - 1))));
    }

    return 0;
}
