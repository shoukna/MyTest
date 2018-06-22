#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=100;
int a[maxn][maxn];
int vis[maxn][maxn];
int maxWall=0;
int rooms=0;
int area=0;
void dfs(int x,int y){
	if(vis[x][y]) return;
	area++;
	vis[x][y]=rooms;
	if((a[x][y]&8)==0) dfs(x+1,y);//当a[x][y]转化为二进制，例如13->1101，其中包含了8(8421)，则为0，否则为1
	if((a[x][y]&4)==0) dfs(x,y+1);
	if((a[x][y]&2)==0) dfs(x-1,y);
	if((a[x][y]&1)==0) dfs(x,y-1);

	return;
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			vis[i][j]=0;
		}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j]==0){
				rooms++;
				area=0;
				dfs(i,j);
				if(area>maxWall) maxWall=area;

			}
		}
	}
	printf("%d\n%d\n",rooms,maxWall);
        return 0;
}