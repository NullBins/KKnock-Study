#include <stdio.h>

void swap(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = temp;
    *z = *x + *y;
    return;
}

int main(void) {
    int a, b, c = 0;
    scanf("%d %d", &a, &b);
    //
    swap(&a, &b, &c);
    printf("a = %d, b = %d, c = %d", a, b, c);
    //
    return 0;
}
