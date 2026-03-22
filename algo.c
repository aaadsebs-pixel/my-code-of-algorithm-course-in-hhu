#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* change(char str[], int *len) {
    *len = strlen(str);
    int *num = (int*)malloc(*len * sizeof(int));
    if (num == NULL) {
        return NULL;
    }
    for (int i = 0; i < *len; i++) {
        num[i] = str[*len - 1 - i] - '0';
    }
    return num;
}

int main() {
    char str1[2500], str2[2500];
    scanf("%s %s", str1, str2);
    int len1,len2;
    int *num1 = change(str1,&len1);
    int *num2 = change(str2,&len2);
    if (num1 == NULL || num2 == NULL) {
        if (num1) free(num1);
        if (num2) free(num2);
        return 1;
    }
    int sum[4010]={0};

    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            int c=0;
            c=num1[j] * num2[i]+sum[j+i];
            sum[j+i] = c%10;
            sum[j+i+1] = c/10+sum[j+i+1];
        }
    }
    int i =len1+len2-1;
    while (sum[i]==0) {
        if (sum[i-1]!=0) {
            i--;
            break;
        }

        i--;
        if (i==0) {
            break;
        }

    }
    for ( ;i>=0; i--) {

        printf("%d", sum[i]);

    }
    free(num1);
    free(num2);
    return 0;
}