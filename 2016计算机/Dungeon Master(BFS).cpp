#include<cstdio>
#include<cstdlib>
#include<iostream> 
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=30+5;
char map[maxn][maxn][maxn];
int sx,sy,sz,ex,ey,ez;
int vis[maxn][maxn][maxn];
int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};
int k,n,m;

struct node{
    int x,y,z,step;
};
int check(int x,int y,int z){
	if(x<0||x>=k||y<0||y>=n||z<0||z>=m||map[x][y][z]=='#'||vis[x][y][z]==1)
		return 1;
	return 0;
}
int bfs(){
    node a,next;
	queue<node>Q;
	a.x=sx;
	a.y=sy;
	a.z=sz;
	a.step=0;
	vis[sx][sy][sz]=1;
	Q.push(a);
	while(!Q.empty()){
		a=Q.front();
		Q.pop();
		if(a.x==ex&&a.y==ey&&a.z==ez)
			return a.step;
		for(int i=0;i<6;i++){
		    next=a;
			next.x=a.x+dx[i];
			next.y=a.y+dy[i];
			next.z=a.z+dz[i];
			if(check(next.x,next.y,next.z))
				continue;
			vis[next.x][next.y][next.z]=1;
			next.step=a.step+1;
			Q.push(next);
		}
	}
	return 0;

}

int main(){
	while(scanf("%d%d%d",&k,&n,&m),n+m+k){
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
			    scanf("%s",map[i][j]);
				for(int r=0;r<m;r++){
					if(map[i][j][r]=='S'){
					    sx=i;
						sy=j;
						sz=r;
					}
					if(map[i][j][r]=='E'){
					    ex=i;
						ey=j;
						ez=r;
					}
				}

			}
		}
		memset(vis,0,sizeof(vis));
		int ans=bfs();
		if(ans)
			printf("Escaped in %d minute(s).\n",ans);
		else printf("Trapped!\n");
	}
}