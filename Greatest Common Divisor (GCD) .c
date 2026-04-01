#include <stdio.h>
int main() {
    int a, b, r;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    while (b != 0) {
        r = b;
        b = a % b;
        a = r;
    }

    printf("GCD: %d\n", a);
    return 0;
}