#include <stdio.h>

void binary_to_hexadecimal(char array[]) {
    int array_length = 0;
    while (array[array_length]) array_length++;

    int binary = 0, hexadecimal = 0, remainder = 0;
    int count = 1;
    char b[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char new_array[2];

    // while (binary != 0) {
    //     remainder = binary % 10;
    //     hexadecimal = hexadecimal + remainder * i;
    //     i = i * 2;
    //     binary = binary / 10;
    // }

    for (int i = array_length - 1; i >= 0; i--) {
        remainder = array[i] - '0';
        hexadecimal = hexadecimal + remainder * count;
        count = count * 2;
        if (i == 4) {
            new_array[1] = b[hexadecimal - 1];
            count = 1;
            hexadecimal = 0;
        }
        if (i == 0) {
            new_array[0] = b[hexadecimal - 1];
        }
    }
    printf("%s\n", new_array);
}

int main() {
    char a[] = "10001111";
    char b[] = "10011110";

    binary_to_hexadecimal(a);
    binary_to_hexadecimal(b);
    return 0;
}