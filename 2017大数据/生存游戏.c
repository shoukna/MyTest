#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 100
int a[maxn][maxn];
int b[maxn][maxn];
int d[8][2]={{-1,1},{-1,0},{-1,-1},{1,1},{1,0},{1,-1},{0,1},{0,-1}};
void build(int x,int y){
	int k=0;
	int i;
	if(a[x][y]==1){
		for(i=0;i<8;i++){
		    int tx=x+d[i][0];
			int ty=y+d[i][1];
			if(a[tx][ty]==1)
				k++;
		}
		if(k<2||k>3) b[x][y]=0;
		if(k==2||k==3) b[x][y]=1;
	}
	else if(a[x][y]==0){
	    for(i=0;i<8;i++){
		    int tx=x+d[i][0];
			int ty=y+d[i][1];
			if(a[tx][ty]==1)
				k++;
		}
		if(k==3) b[x][y]=1;
		
	}

}
int main(){
	int i,j;
	int m,n;
	scanf("%d%d",&m,&n);
	memset(a,-1,sizeof(a));
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			build(i,j);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			printf("%d ",b[i][j]);
	    printf("\n");
	}
}