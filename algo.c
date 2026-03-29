#include <stdio.h>

int stepA[4], stepB[4], stepR[4];
char stepOp[4];
int stepCount = 0;

int equal(int a,int b) {
    if (a==b) return 1;
    else return 0;
}

int solve(int arr[],int n,int depth) {
    if (n==1) {
        if (equal(arr[0],24)) {
            stepCount = depth;
            return 1;
        }
        return 0;
    } else {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (i==j) continue;

                int temp[4]={0};
                int k=0;
                for (int m=0;m<n;m++) {
                    if (m!=i && m!=j) temp[k++]=arr[m];
                }

                // +
                temp[k]=arr[i]+arr[j];
                stepA[depth]=arr[i]; stepB[depth]=arr[j]; stepOp[depth]='+'; stepR[depth]=temp[k];
                if (solve(temp,k+1,depth+1)) return 1;

                // -
                temp[k]=arr[i]-arr[j];
                stepA[depth]=arr[i]; stepB[depth]=arr[j]; stepOp[depth]='-'; stepR[depth]=temp[k];
                if (solve(temp,k+1,depth+1)) return 1;

                // *
                temp[k]=arr[i]*arr[j];
                stepA[depth]=arr[i]; stepB[depth]=arr[j]; stepOp[depth]='*'; stepR[depth]=temp[k];
                if (solve(temp,k+1,depth+1)) return 1;

                // /
                if (arr[j]!=0 && arr[i]%arr[j]==0) {
                    temp[k]=arr[i]/arr[j];
                    stepA[depth]=arr[i]; stepB[depth]=arr[j]; stepOp[depth]='/'; stepR[depth]=temp[k];
                    if (solve(temp,k+1,depth+1)) return 1;
                }
            }
        }
        return 0;
    }
}

int main(){
    int arr[4]={0};
    for (int i=0;i<4;i++) scanf("%d",&arr[i]);

    int m=solve(arr,4,0);
    if (m) {
        for (int s=0;s<stepCount;s++) {
            printf("%d%c%d=%d\n", stepA[s], stepOp[s], stepB[s], stepR[s]);
        }
    } else {
        printf("No answer!\n");
    }
    return 0;
}
