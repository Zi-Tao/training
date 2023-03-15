#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_LOTTO_NUMBER 7
#define MAX_NUMBER 69
#define MAX_SPECIAL_NUMBER 10

void generateLottoNumbers(int* lotto_numbers, int* special_number) {
    // 產生1~MAX_NUMBER的數字
    for (int i = 0; i < TOTAL_LOTTO_NUMBER - 1; i++) {
        lotto_numbers[i] = rand() % MAX_NUMBER + 1;
    }

    // 產生1~MAX_SPECIAL_NUMBER的特別號
    *special_number = rand() % MAX_SPECIAL_NUMBER + 1;

    // 檢查是否有重複的號碼，若有則重新產生
    for (int i = 0; i < TOTAL_LOTTO_NUMBER - 1; i++) {
        for (int j = i + 1; j < TOTAL_LOTTO_NUMBER - 1; j++) {
            if (lotto_numbers[i] == lotto_numbers[j]) {
                lotto_numbers[i] = rand() % MAX_NUMBER + 1;
                i = -1;
                break;
            }
        }
    }

    // 檢查特別號是否和前六個數字有重複，若有則重新產生
    for (int i = 0; i < TOTAL_LOTTO_NUMBER - 1; i++) {
        if (*special_number == lotto_numbers[i]) {
            *special_number = rand() % MAX_SPECIAL_NUMBER + 1;
            i = -1;
        }
    }

    // 將數字排序
    for (int i = 0; i < TOTAL_LOTTO_NUMBER - 2; i++) {
        for (int j = 0; j < TOTAL_LOTTO_NUMBER - i - 2; j++) {
            if (lotto_numbers[j] > lotto_numbers[j + 1]) {
                int temp = lotto_numbers[j];
                lotto_numbers[j] = lotto_numbers[j + 1];
                lotto_numbers[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩(1~5): ");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("輸入錯誤，結束程式\n");
        return 0;
    }

    // 開啟檔案
    FILE* fp;
    fp = fopen("lotto.txt", "w");

    // 寫入資料
    fprintf(fp, "======== lotto649 ========\n");
    
    // fprintf(fp, "購買時間: ");
    fprintf(fp, "= ");
    time_t now = time(NULL);
    fprintf(fp, "%s", ctime(&now));
    // fprintf(fp, "購買組數: %d\n", n);

    // 產生n組樂透號碼並寫入檔案
    for (int i = 0; i < n; i++) {
        int lotto_numbers[TOTAL_LOTTO_NUMBER - 1];
        int special_number;
        generateLottoNumbers(lotto_numbers, &special_number);
        // fprintf(fp, "樂透號碼 %d: ", i + 1);
        fprintf(fp, "[%d]: ", i + 1);
        for (int j = 0; j < TOTAL_LOTTO_NUMBER - 1; j++) {
            fprintf(fp, "%02d ", lotto_numbers[j]);
        }
        // fprintf(fp, "特別號: %02d\n", special_number);
        fprintf(fp, "%02d\n", special_number);
    }
    if (n < 5) {
        for (int i = n + 1; i <= 5; i++) {
            fprintf(fp, "[%d]: ", i);
            for (int j = 0; j < TOTAL_LOTTO_NUMBER; j++) {
                fprintf(fp, "-- ");
            }
            fprintf(fp, "\n");
        }
    }

    fprintf(fp, "======== csie@CGU ========");

    // 關閉檔案
    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}