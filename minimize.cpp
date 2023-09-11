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

    // �������ļ�
    inputFile = fopen("content.html", "r");
    if (inputFile == NULL) {
        printf("�޷��������ļ���\n");
        return 1;
    }

    // ������������ļ�
    outputFile = fopen("content.min.html", "w");
    if (outputFile == NULL) {
        printf("�޷���������ļ���\n");
        return 1;
    }

    // ɾ�����з����ĸ�һ��Ŀո�
    removeNewlinesAndSpaces(inputFile, outputFile);

    // �ر��ļ�
    fclose(inputFile);
    fclose(outputFile);

    printf("������ɡ�\n");

    getchar();
    return 0;
}