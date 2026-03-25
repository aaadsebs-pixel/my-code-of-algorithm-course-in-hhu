#include <stdio.h>
#include <string.h>
int arr[10]={0};
void get(int a) {
    arr[a%10]=1;
    arr[a/10%10]=1;
    arr[a/100]=1;
}
int main() {
    int a,b,c;
    int d=0,e=0,count=0;
    scanf("%d%d%d",&a,&b,&c);
    for (int i=123;i<988;i++) {
        if(i*b%a||i*c%a) continue;
        d=i*b/a;
        e=i*c/a;
        if (d>987||e>987) break;
        get(i);
        get(d);
        get(e);
        int j=1;
        for (;j<10;j++) {
            if (arr[j]==0) break;
        }
if (j==10) {
    printf("%d %d %d\n",i,d,e);
    count++;
}
memset(arr,0,sizeof(arr));
    }
    if (count==0) printf("No!!!");
    return 0;
}