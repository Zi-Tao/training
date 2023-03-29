#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;

void generateLottoNumbers(int lotto[]) {
    for (int i = 0; i < 7; i++) {
        int number = 0;
        int check = 0;

        if (i == 6) {
            number = rand() % 10 + 1; // 特別號
        } else {
            number = rand() % 69 + 1;
        }
        for (int j = 0; j <= i; j++) {
            if (number == lotto[j]) {
                check = 1;
                i--;
                break;
            }
        }
        if (check == 0) {
            lotto[i] = number;
        }
    }

    for (int i = 0; i < 6; i++) { // sort
        int temp = 0;
        for (int j = 6 - 1; j > i; j--) {
            if (lotto[j] < lotto[j - 1]) {
                temp = lotto[j];
                lotto[j] = lotto[j - 1];
                lotto[j - 1] = temp;
            }
        }
    }
}

void check_record(int bingo[], int bingo_n) {
    int check_win = 0;
    int lotto[7] = {0};
    lotto_record_t record;

    FILE* fp_record = fopen("record.bin", "rb+");

    if (fp_record == NULL) {
        printf("\n目前尚未購買彩券。\n");
    } else {
        printf("\n以下為中獎彩券：\n");
        while (fread(&record, sizeof(lotto_record_t), 1, fp_record)) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 7; j++) {
                    for (int x = 0; x < bingo_n; x++) {
                        if (record.lotto_set[i][j] == bingo[x]) {
                            check_win = 1;
                            printf("彩券 No.%d\n", record.receipt_id);
                            printf("售出時間：%s\n", record.receipt_time);
                            printf("號碼：");
                            for (int k = 0; k < 7; k++) {
                                printf("%02d ", record.lotto_set[i][k]);
                            }
                            printf("\n");
                            i++;
                        }
                    }
                }
            }
        }
        if (check_win == 0) {
            printf("\n查無中獎彩券!\n");
        }
        fclose(fp_record);
    }
}

void write_record(char filename[], int lotto_n, int sell_n) {
    int lotto[7] = {0};
    lotto_record_t new_record;
    time_t now = time(NULL);
    char* now_time = ctime(&now);

    FILE* fp_record = fopen("record.bin", "ab+");
    FILE* fp_lotto_txt = fopen(filename, "w+");

    fprintf(fp_lotto_txt, "========= lotto649 =========\n");

    new_record.receipt_id = sell_n + 1;
    fprintf(fp_lotto_txt, "========+ No.%05d +========\n", new_record.receipt_id);

    new_record.receipt_price = 100 * lotto_n;

    strcpy(new_record.receipt_time, now_time);
    new_record.receipt_time[strlen(new_record.receipt_time) - 1] = '\0';
    fprintf(fp_lotto_txt, "= %s =\n", new_record.receipt_time);

    for (int i = 0; i < 5; i++) {
        fprintf(fp_lotto_txt, "[%d]: ", i + 1);

        if (i < lotto_n) {
            generateLottoNumbers(lotto);
            for (int j = 0; j < 7; j++) {
                new_record.lotto_set[i][j] = lotto[j];
                fprintf(fp_lotto_txt, "%02d ", new_record.lotto_set[i][j]);
            }
            fprintf(fp_lotto_txt, "\n");
        } else {
            for (int j = 0; j < 7; j++) {
                new_record.lotto_set[i][j] = 0;
            }
            fprintf(fp_lotto_txt, "-- -- -- -- -- -- -- \n");
        }
    }

    fprintf(fp_lotto_txt, "========= csie@CGU =========\n");

    fclose(fp_lotto_txt);
    printf("已將您購買的%d組樂透組合輸出至lotto[%05d].txt\n", lotto_n, new_record.receipt_id);

    fwrite(&new_record, sizeof(lotto_record_t), 1, fp_record);
    fclose(fp_record);
}

int main() {
    int lotto_n, sell_n, bingo_n;
    int bingo[3] = {0};
    char filename[20] = {0};
    srand(time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩(1~5)[0為兌獎模式]: ");
    scanf("%d", &lotto_n);

    if (lotto_n < 0 || lotto_n > 5) {
        printf("輸入的數值錯誤！\n");
        return 1;
    } else {
        lotto_record_t record;
        FILE* fp_record = fopen("record.bin", "rb");

        if (fp_record == NULL) {
            sell_n = 0;
        } else {
            while (fread(&record, sizeof(lotto_record_t), 1, fp_record)) {
                sell_n = record.receipt_id;
            }
            fclose(fp_record);
        }

        sprintf(filename, "lotto[%05d].txt", sell_n + 1);

        if (lotto_n == 0) {
            printf("請輸入中獎號碼 (最多三個): ");
            for (int i = 0; i < 3; i++) {
                scanf("%d", &bingo[i]);
                bingo_n = i + 1;
                char get_char = getchar();
                if (get_char == '\n') {
                    break;
                }
            }

            printf("輸入之中獎號碼為: ");
            for (int i = 0; i < bingo_n; i++) {
                printf("%02d ", bingo[i]);
            }
            printf("\n");

            check_record(bingo, bingo_n);
        } else {
            write_record(filename, lotto_n, sell_n);
        }
    }

    return 0;
}