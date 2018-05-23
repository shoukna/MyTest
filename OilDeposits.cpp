#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
using namespace std;
const int maxn=1000;
char s[maxn][maxn];
int idx[maxn][maxn];
int m,n;
void dfs(int r,int c,int id){
	if(r>=m||r<0) return;
	if(c>=n||c<0) return;
	if(idx[r][c]>0||s[r][c]!='@') return;
	idx[r][c]=id;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
		    if(i!=0||j!=0) dfs(r+i,c+j,id);
		}
	}
}

int main(){
	while(scanf("%d%d",&m,&n)==2&&m&&n){
		for(int i=0;i<m;i++){
		    scanf("%s",s[i]);
		}
		memset(idx,0,sizeof(idx));
		int cnt=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
			    if(idx[i][j]==0&&s[i][j]=='@') dfs(i,j,++cnt);			
			}			
		}
		printf("%d\n",cnt);	
	}
	return 0; 
}
