#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binary.c"
#include "ternary.c"


int main() {
    printf("Hello World\n");

    int a = 10, b = 31, len = 5;
    uint8_t* bi_a = fromDec(a, len);
    uint8_t* bi_b = fromDec(b, len);

    printf("a is %d\n", a);
    printf("a(binart)");
    showBinary(bi_a, len);
    printf("a(trans back) %d\n", toDec(bi_a, len));

    printf("b is %d\n", b);
    printf("b(binart)");
    showBinary(bi_b, len);
    printf("b(trans back) %d\n", toDec(bi_b, len));


    uint8_t* a_p_b = B_ADD(bi_a, bi_b, len);
    printf("a+b is %d\n", a + b);
    printf("a+b(binart)");
    showBinary(a_p_b, len);
    printf("a+b(trans back) %d\n", toDec(a_p_b, len));
    return 0;
}
