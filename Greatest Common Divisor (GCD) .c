#include <stdio.h>
int main() {
    int a, b, value;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    while (b != 0) {
        value = b;
        b = a % b;
        a = value;
    }

    printf("GCD: %d\n", a);
    return 0;
}