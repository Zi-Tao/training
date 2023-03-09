#include <stdio.h>

int main() {
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int i = 4;
    int count = 0;
    int a_length = 0;

    while (a[a_length]) {
        if (a[a_length] == ' ') {
            count++;
        } else if (a[a_length] == '-') {
            count++;
        }
        a_length++;
    }

    int array[a_length - count];
    int k = 1;
    int x = 0;

    for (int j = 0; j < a_length; j++) {
        if (a[j] == ' ') {
            // count++;
            j++;
        }
        if (a[j] == '-') {
            k = -1;
            a[j + 1] = k * (a[j + 1] - '0');
        } else {
            if (a[j] >= '1' && a[j] <= '9') {
                a[j] -= '0';
            }
            array[x] = a[j];
            x++;
        }
    }

    for (int y = 0; y < a_length - count - 1; y++) {
        // printf("%d\n",array[y]);
        for (int z = 0; z < a_length - count - y - 1; z++) {
            if (array[z + 1] > array[z]) {
                int tmp = array[y];
                array[y] = array[z];
                array[z] = tmp;
            }
        }
    }
    printf("%d\n", array[i - 1]);
    return 0;
}