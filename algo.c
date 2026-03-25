#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int get(int arr[],int n) {
    for (int i=0;i<n;i++) {
        if (arr[i]==arr[n]||abs(arr[i]-arr[n])==abs(i-n)) return 0;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
int*jp=(int*)calloc(n,sizeof(int));
    if (jp==NULL) {
        free(jp);
        return 0;
    }
    int count=0;
    int i=0;
    int j=0;
    while (i>=0) {

        for (;j<n;j++) {
            jp[i]=j;
            if (get(jp,i))break;
        }
        if (j<n) {
            if (i==n-1) {
                count++;
                if (count<4) {
                    for (int m=0;m<n;m++) {
                        printf("%d ",jp[m]+1);
                    }
                    printf("\n");
                }
                    jp[i]=0;
                i--;
                j=jp[i]+1;

            }
            else  {
                jp[i]=j;
                i++;
                j=0;
            }
        }
        else {
            i--;
            j=jp[i]+1;
        }



    }
    printf("%d",count);
    free(jp);
    return 0;
}