#include <stdio.h>
#include "mymath.h"

int main(int argc, char *argv[] ) {
    int a = 10;
    int b = 5;
    printf("a+b=%d\n", add(a,b));
    printf("a-b=%d\n", sub(a,b));
    printf("a*b=%d\n", mul(a,b));
    return 0;
}
