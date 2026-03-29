#include <stdio.h>
#include <string.h>
int arr[100][100]={0};
int brr[100][100]={0};
int n=0,m=0;
void change(char str[], int k,int m) {
    for (int i = 0; i < m; i++) {
        arr[k][i] = str[m - 1 - i] - '0';
    }
}
void flood(int x, int y,int arr[100][100],int brr[100][100]) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    if(x<0 || x>n || y<0 || y>m) return;
    if(brr[x][y]||arr[x][y]==0) return;
    else {
        brr[x][y] =1;
            for(int i=0;i<4;i++) {
                int nx=x+dx[i];
                int ny=y+dy[i];
                flood(nx,ny,arr,brr);
            }
        }
    }

int main() {
    scanf("%d%d",&n,&m);

    int count=0;
    for(int i=0;i<n;i++) {
        char str[100];
        scanf("%s",str);
        change(str,i,m);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]&&brr[i][j]==0) count++;
            flood(i,j,arr,brr);
        }
    }
    printf("%d",count);
    return 0;
}
