#include<cstdio>
#include<string.h>
#include<cstdlib>
using namespace std;
#define maxn 100+5
char str[maxn][maxn];
char s[maxn];
int x1,yy,x2,y2,n;
int len;
bool dfs(int deep,int x,int y,int k,int kk){
	if(deep>len){
	    x2=x-k;
		y2=y-kk;
		return true;
	} 
	if(x<=0||x>n||y<=0||y>n) return false;
	if(str[x][y]!=s[deep]) return false;
	return dfs(deep+1,x+k,y+kk,k,kk);
}

bool finding(char *s){
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
			if(str[i][j]==s[1]){
				for(int k=-1;k<=1;k++)
					for(int kk=-1;kk<=1;kk++){
						if(k!=0||kk!=0){
						    if(dfs(1,i,j,k,kk)){
						        x1=i;yy=j;
							    return true;
						    }

						}
					}		
			}
		}
	}
	return false;
}

int main(){	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		   scanf("%s",str[i]+1);
	}
	while(scanf("%s",s+1)!=0&&s[1]!='0'){
	    len=strlen(s+1);
		if(finding(s))
		    printf("%d,%d %d,%d\n",x1,yy,x2,y2);
		else printf("Not found\n");
	}
	
	return 0;
}
