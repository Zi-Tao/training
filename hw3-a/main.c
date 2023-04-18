#include <stdio.h>
#include <time.h>

void Hanoi(FILE* file, int* step, int n, char one, char two, char three) {
    time_t t;
    struct tm* tp;
    char time_buffer[20];

    if (n == 1) {
        time(&t);
        tp = localtime(&t);
        strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
        fprintf(file, "%7d (%s): %dP from %c to %c\n", *step, time_buffer, 1, one, three);
        (*step)++;
    } else {
        Hanoi(file, step, n - 1, one, three, two);
        time(&t);
        tp = localtime(&t);
        strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
        fprintf(file, "%7d (%s): %dP from %c to %c\n", *step, time_buffer, n, one, three);
        (*step)++;
        Hanoi(file, step, n - 1, two, one, three);
    }
}

int main() {
    int plate = 20;
    int step = 1;

    time_t t;
    struct tm* tp;
    char time_buffer[20];
    FILE* file = fopen("hanoi.txt", "w+");

    time(&t);
    tp = localtime(&t);
    strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
    fprintf(file, "%s\n", time_buffer);

    Hanoi(file, &step, plate, 'A', 'B', 'C');

    time(&t);
    tp = localtime(&t);
    strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
    fprintf(file, "%s\n", time_buffer);

    fclose(file);
    return 0;
}