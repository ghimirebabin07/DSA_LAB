#include <stdio.h>

void tower(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
    } else {
        tower(n-1, source, dest, aux);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        tower(n-1, aux, source, dest);
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C');

    return 0;
}