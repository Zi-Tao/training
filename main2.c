#include <stdio.h>

int main() {
    char a[] = "A3B2C4A9";
    int a_length = 0;
    while (a[a_length]) a_length++;

    for (int i = 0; i < a_length; i++) {
        int count = 0;
        if (a[i] >= '1' && a[i] <= '9') {
            count = a[i] - '0';
            for (int j = 0; j < count; j++) {
                printf("%c", a[i - 1]);
            }
        }
    }
    return 0;
}