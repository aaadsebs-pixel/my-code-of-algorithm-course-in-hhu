#include <stdio.h>
#include <stdlib.h>
int n;
void flood(int x, int y,int arr[n][n],int brr[n][n]) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    if(x<0 || x>=n || y<0 || y>=n) return;
    if(brr[x][y]||arr[x][y]!=0) return;
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
    scanf("%d",&n);
    int(*arr)[n]=(int(*)[n])calloc(n*n,sizeof(int));
    int(*brr)[n]=(int(*)[n])calloc(n*n,sizeof(int));
    if(arr==NULL || brr==NULL) return-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            if(j==0) {
                if(arr[i][j]==0 && brr[i][j]==0) {
                    flood(i,j,arr,brr);
                }
                if(arr[j][i]==0 && brr[j][i]==0) {
                    flood(j,i,arr,brr);
                }

            }
                else {
                    if(arr[i][n-1]==0 && brr[i][n-1]==0) {
                    flood(i,n-1,arr,brr);
                }
                    if(arr[n-1][i]==0 && brr[n-1][i]==0) {
                        flood(n-1,i,arr,brr);
                    }
            }
        }
    }
for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
        if (arr[i][j]==0 && brr[i][j]==0) {
            arr[i][j]=2;
        }
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}

    free(arr);
    free(brr);
    return 0;
}