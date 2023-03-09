#include <stdio.h>

int is_lowercase(char a) {
    if (a >= 'a' && a <= 'z') return 1;
    return 0;
}

int main() {
    char a[] = "Hello";
    char b[64] = {0};
    char tmp1, tmp2;
    int a_length = (int)sizeof(a) / sizeof(char) - 1;
    printf("%s\n", a);
    char d = ('a' - 'A');
    for (int i = 0, j = a_length - 1; i < j; i++, j--) {
        tmp1 = a[i];
        tmp2 = a[j];
        if (is_lowercase(a[i]) && !is_lowercase(a[j])) {
            tmp1 -= d;
            tmp2 += d;
        } else if (!is_lowercase(a[i]) && is_lowercase(a[j])) {
            tmp1 += d;
            tmp2 -= d;
        }
        a[i] = tmp2;
        a[j] = tmp1;
    }
    printf("%s\n", a);
    return 0;
}