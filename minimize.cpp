#include <stdio.h>
#include <string.h>

void removeNewlinesAndSpaces(FILE* input, FILE* output) {
    char str[2048];

    while ((fgets(str, 2048, input)) != NULL) {
        int i = 0;
        int len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
            len--;
        }
        while (str[i] == ' ') {
            i++;
        }
        if (i > 0) {
            memmove(str, str+i, len-i+1);
        }
        fprintf(output, "%s", str);
    }
}

int main() {
    FILE* inputFile;
    FILE* outputFile;

    // 打开输入文件
    inputFile = fopen("content.html", "r");
    if (inputFile == NULL) {
        printf("无法打开输入文件。\n");
        return 1;
    }

    // 创建并打开输出文件
    outputFile = fopen("content.min.html", "w");
    if (outputFile == NULL) {
        printf("无法创建输出文件。\n");
        return 1;
    }

    // 删除换行符和四个一组的空格
    removeNewlinesAndSpaces(inputFile, outputFile);

    // 关闭文件
    fclose(inputFile);
    fclose(outputFile);

    printf("处理完成。\n");

    getchar();
    return 0;
}