#include <stdio.h>
#include <stdlib.h>
int n,m;
int l[8]={0,1,1,1,0,-1,-1,-1};
int w[8]={1,1,0,-1,-1,-1,0,1};
void change(int arr[n][m],int brr[n][m],int x,int y) {
    if (arr[x][y]) {
        brr[x][y] =66;
    }
    else {
        for (int i=0;i<8;i++) {
            int dx = x+l[i];
            int dy = y+w[i];
            if (dx>=0 && dx<n && dy>=0 && dy<m) {
                brr[x][y]+=arr[dx][dy];
            }
        }
    }
}
void flood(int x, int y,int brr[n][m],int crr[n][m]) {
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(brr[x][y]==66||crr[x][y]) return;
    else {
        crr[x][y] =1;
        if (brr[x][y]==0) {
            for(int i=0;i<8;i++) {
                int nx=x+l[i];
                int ny=y+w[i];
                flood(nx,ny,brr,crr);
            }
        }
    }
}



int main() {
    scanf("%d %d",&n,&m);
    int(*arr)[m] = (int(*)[m])calloc(n*m,sizeof(int));
    int(*brr)[m] = (int(*)[m])calloc(n*m,sizeof(int));
    int(*crr)[m] = (int(*)[m])calloc(n*m,sizeof(int));
    if(arr==NULL||brr==NULL||crr==NULL) return -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) change(arr,brr,i,j);
    }
    int count=0;
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++) {
            if (crr[k][j]==0&&brr[k][j]==0) {
                count++;
                flood(k,j,brr,crr);
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++) {
            if (crr[k][j]==0&&brr[k][j]!=66) {
                count++;
                flood(k,j,brr,crr);
            }
        }
    }
    printf("%d\n",count);

    free(arr);
    free(brr);
    free(crr);
    return 0;
}