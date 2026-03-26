#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#include<stdio.h>
#include<stdlib.h>


int  fun(int x,int arr[],int mdp,int mt,int nm,int sum) {
    if (x>mdp-1) {
        mt=max(mt,sum-nm);
        return mt;
    }
    int result=fun(x+1,arr, mdp, mt, nm, sum);
    if (nm+arr[x]<=sum/2) {
        nm+=arr[x];
        result=min(fun(x+1,arr, mdp, mt, nm, sum),result);
    }
    return result;

}
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int*a1=(int*)calloc(a,sizeof(int));
    int*b1=(int*)calloc(b,sizeof(int));
    int*c1=(int*)calloc(c,sizeof(int));
    int*d1=(int*)calloc(d,sizeof(int));
    if(a1==NULL || b1==NULL || c1==NULL || d1==NULL) {
        free(a1);
        free(b1);
        free(c1);
        free(d1);
        return -1;
    }
    for(int i=0;i<a;i++) {
        scanf("%d",&a1[i]);
    }
    for(int j=0;j<b;j++) {
        scanf("%d",&b1[j]);
    }
    for(int k=0;k<c;k++) {
        scanf("%d",&c1[k]);
    }
    for(int l=0;l<d;l++) {
        scanf("%d",&d1[l]);
    }
    int ma=0,mb=0,mc=0,md=0;
    int mdp=0,mt=0,nm=0,sum=0;
    for(int i=0;i<a;i++) {
        sum+=a1[i];
    }
    ma=fun(0,a1,a,ma,nm,sum);
     mdp=0;mt=0;nm=0;sum=0;
    for(int i=0;i<b;i++) {
        sum+=b1[i];
    }
    mb=fun(0,b1,b,mb,nm,sum);
    mdp=0;mt=0;nm=0;sum=0;
    for(int i=0;i<c;i++) {
        sum+=c1[i];
    }
    mc=fun(0,c1,c,mc,nm,sum);
    mdp=0;mt=0;nm=0;sum=0;
    for(int i=0;i<d;i++) {
        sum+=d1[i];
    }
    md=fun(0,d1,d,md,nm,sum);
    printf("%d\n",ma+mb+mc+md);
    free(a1);
    free(b1);
    free(c1);
    free(d1);
    return 0;
}