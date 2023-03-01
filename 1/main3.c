#include <stdio.h>

int main() {
    char a[] = "ABCabcABC";
    int shift = 4;
    int a_length = sizeof(a) / sizeof(char) - 1;
    shift %= a_length;
    printf("%s\n", a);
    printf("%d\n", shift);
    for (int i = 0; i < shift; i++) {
        char tmp = a[0];
        for (int j = 0; j < a_length - 1; j++) {
            a[j] = a[j + 1];
        }
        a[a_length - 1] = tmp;
    }
    printf("%s\n", a);
    return 0;
}