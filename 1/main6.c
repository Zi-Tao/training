#include <stdio.h>

char array[9][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

int main() {
    char a[] = "81c8g8u168";
    int a_length = 0;
    while (a[a_length]) a_length++;

    for (int j = 0; j < a_length; j++) {
        if (a[j] >= '1' && a[j] <= '9') {
            a[j] -= '0';
            printf("%s ", array[a[j] - 1]);
        } else {
            printf("%c ", a[j]);
        }
    }
    return 0;
}