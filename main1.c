#include <stdio.h>

int main() {
    char a[] = "AABBBCCCCddd";
    int a_length = 0;
    while (a[a_length]) a_length++;

    for (int i = 0; i < a_length; i++) {
        int count = 1;
        while (i < a_length - 1 && a[i] == a[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", a[i], count);
    }
    return 0;
}