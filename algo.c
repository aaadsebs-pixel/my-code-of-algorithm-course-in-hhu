#include <stdio.h>
#include <stdlib.h>
long  seqnum(int n,long b[]) {//防止越界，不用int

    if (n==1) return b[1]=1;
    for (int i=1 ;i<=n/2;i++) {
        if (b[i]==0) {
            b[i]=seqnum(i,b);
            b[n]+=b[i];
        }
        else {
            b[n]+=b[i];
        }
    }
     b[n]=b[n]+1;

    return b[n];
}
int main() {
    int n=0;
    scanf("%d",&n);
    long*c=(long*)calloc(n+1,sizeof(long));
printf("%ld",seqnum(n,c));
    free(c);
    return 0;
}