#include <stdio.h>

int main() {
    FILE* fp;
    char c;

    // 開啟main2.txt檔案，使用"w"選項可以將文件清空，重新寫入
    fp = fopen("main2.txt", "w");

    // 開啟目前執行的程式檔案
    FILE* current_file = fopen(__FILE__, "r");

    // 讀取當前程式碼文件的每個字符，並寫入到main2.txt中
    while ((c = fgetc(current_file)) != EOF) {
        fputc(c, fp);
    }

    // 關閉檔案
    fclose(fp);
    fclose(current_file);

    printf("程式碼已寫入main2.txt文件中\n");
    return 0;
}
