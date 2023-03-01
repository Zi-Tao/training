#include <stdio.h>

void get_number(char array[]) {
    int array_length = 0;
    while (array[array_length]) array_length++;

    int j = 1;
    int k, total = 0;
    for (int i = 0; i < array_length; i++) {
        if (array[i] < 'A' || array[i] > 'Z' && array[i] < 'a' || array[i] > 'z') {
            total *= 10;
            if (array[i] == '-') {
                j = -1;
            } else {
                k = array[i] - '0';
                total += k;
            }
        }
    }
    printf("%d\n", j * total);
}

int main() {
    char a[] = "-99acbc";
    char b[] = "99acbc";
    char c[] = "ac-99bc";

    get_number(a);
    get_number(b);
    get_number(c);
    return 0;
}