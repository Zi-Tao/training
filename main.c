#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[] = {1, 2, 3};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    int array1[3]={};

    if ((fp = fopen("a.bin", "wb+")) == NULL) {
        printf("無法開啟");
        exit(1);
    }
    if (fwrite(a, sizeof(a), 1, fp) != 1) {
        printf("寫入檔案失敗\n");
    }
    fseek(fp, 0, SEEK_SET);
    if (fread(array1, sizeof(array1), 1, fp) != 1) {
        printf("讀取檔案失敗\n");
    } else {
        printf("a陣列:\n");
        for(int i=0;i<3;i++){
            printf("%d\n",array1[i]);
            // printf("%lu",fread(a[i], sizeof(a), 1, fp));
        }
    }
    return 0;
}