#include <stdio.h>
#define MAX_LEN 200

int seq[MAX_LEN];
static void dfs123(int c1, int c2, int c3, int depth, int total_len) {
    if (depth == total_len) {
        for (int i = 0; i < total_len; ++i) {
            if (i) printf(" ");
            printf("%d", seq[i]);
        }
        printf("\n");
        return;
    }

    // 按 1,2,3 的顺序尝试，输出天然为字典序
    if (c1 > 0) {
        seq[depth] = 1;
        dfs123(c1 - 1, c2, c3, depth + 1, total_len);
    }
    if (c2 > 0) {
        seq[depth] = 2;
        dfs123(c1, c2 - 1, c3, depth + 1, total_len);
    }
    if (c3 > 0) {
        seq[depth] = 3;
        dfs123(c1, c2, c3 - 1, depth + 1, total_len);
    }
}
void print_permutations_123(int c1, int c2, int c3) {
    if (c1 < 0 || c2 < 0 || c3 < 0) return;

    int total_len = c1 + c2 + c3;
    if (total_len > MAX_LEN) return;

    dfs123(c1, c2, c3, 0, total_len);
}

int combination(int n, int k,int arr[11][11]) {
    if (k == 0 || n == k) {
        return 1;
    }
    if (arr[n][k] !=0) {
        return arr[n][k];
    }
    else if (n<k) return 0;
    arr[n][k] = combination(n - 1, k - 1,arr) + combination(n - 1, k,arr);
    return arr[n][k];
}
int main() {
    int n;
    int m=0;
    int arr[11][11]={0};
    scanf("%d",&n);
    if (n<10||n>30) {
        printf("%d",m);
        return 0;
    }

    int l=n-10;
    int ans[21]={0};
    for (int i=l/2;i>=0;i--) {
        int x=l-2*i;
        if (x>10) break;
        ans[n-10]+=combination(10,x,arr)*combination(10-x,i,arr);
    }
    int a=ans[n-10];
    printf("%d\n",a);
    for (int i=l/2;i>=0;i--) {
        int x=l-2*i;
        if (x>10) break;
       // ans[n-10]+=combination(10,x,arr)*combination(10-x,i,arr);
        print_permutations_123(10-x-i,x,i);
    }


    return 0;
}