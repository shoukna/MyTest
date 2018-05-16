#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define maxn 100
int arr[maxn][3];
int m,n;
int p,x,y,len;
int find(int len,int p,int x,int y){
	if(p=='V') return 0;
	int aa=1,bb=1,cc=1,dd=1;
	int i=0;
	int j=0;
	for(i=y;i<y+len;i++){
		for(j=0;j<m;j++)
		    if(arr[j][0]=='H'&&arr[j][1]==x&&arr[j][2]==i) break;
		if(j==m) aa=0;
	}
	for(i=y;i<y+len;i++){
		for(j=0;j<m;j++)
		    if(arr[j][0]=='H'&&arr[j][1]==x+len&&arr[j][2]==i) break;
		if(j==m) bb=0;
	}
	for(i=x;i<x+len;i++){
		for(j=0;j<m;j++)
		    if(arr[j][0]=='V'&&arr[j][1]==y&&arr[j][2]==i) break;
		if(j==m) cc=0;
	}
	for(i=x;i<x+len;i++){
		for(j=0;j<m;j++)
		    if(arr[j][0]=='V'&&arr[j][1]==y+len&&arr[j][2]==i) break;
		if(j==m) dd=0;
	}
	if(aa&&bb&&cc&&dd) return 1;
	return 0;
}
int main(){
	int rnd=0;
	int i=0,j=0;
	while(scanf("%d%d",&n,&m)==2){ //n为边长，m为线段数量
		for(i=0;i<m;i++){
		    scanf("%s%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		}
	
		if(rnd)
			printf("\n**********************************\n\n");
		printf("round %d\n",++rnd);
		int flag=0;
		for(i=1;i<n;i++){
			int count=0;
			for(j=0;j<m;j++){
				if(find(i,arr[j][0],arr[j][1],arr[j][2])){
				    count++;
					flag=1;
				}
			}
		  if (count)  
                printf("%d square (s) of size %d\n", count, i);  
        }  
        if (!flag)  
            printf("No completed squares can be found.\n");  
    } 
    return 0;
}
