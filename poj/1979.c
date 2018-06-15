#include<stdio.h>
#include<stdlib.h>
int h,w;
char z[25][25];
int f(int x,int y){
    if(x>=w||y>=h||x<0||y<0) return 0;
	if(z[x][y]=='#') return 0;
	else{
		z[x][y]='#';
		return 1+f(x-1,y)+f(x+1,y)+f(x,y-1)+f(x,y+1);
	}
}
int main(){
	int i,j;
	while(scanf("%d%d",&h,&w)==2&&h!=0&&w!=0){
		for(i=0;i<w;i++)
			scanf("%s",z[i]);
		for(i=0;i<w;i++)
			for(j=0;j<h;j++){
			     if(z[i][j]=='@') printf("%d\n",f(i,j));
			}
				
	}
return 0;
}
