#include <stdio.h>
#include <stdlib.h>
long long w(long long a,long long b,long long c, long long arr[21][21][21]) {

    if (a<=0||b<=0||c<=0) {
        return  arr[0][0][0];
    }
    else if (a>20||b>20||c>20) {
        return w(20,20,20,arr);
    }
    else if (arr[a][b][c]) return arr[a][b][c];
    else if (a<b&&b<c) {
        //如果 a<b 并且 b<c 就返回 w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)。
        arr[a][b][c]= w(a,b,c-1,arr)+w(a,b-1,c-1,arr)-w(a,b-1,c,arr);
        return arr[a][b][c];
    }
    else {
        //w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)
         arr[a][b][c]=w(a-1,b,c,arr)+w(a-1,b-1,c,arr)+w(a-1,b,c-1,arr)-w(a-1,b-1,c-1,arr);
        return arr[a][b][c];
    }
}
int main() {
    long long arr[21][21][21]={0};
    long long a=0,b=0,c=0;
    arr[0][0][0]=1;
    while (1) {
        scanf("%lld%lld%lld",&a,&b,&c);
        if (a==-1&&b==-1&&c==-1) break;
        long long s=w(a,b,c,arr);
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,s);

    }
    return 0;
}