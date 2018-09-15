#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 100000
int n,m;
int f[maxn];
struct node{
	int u;
	int v;
	int w;
}edge[maxn];
void init(int n){
	for(int i=0;i<=n;i++)
		f[i]=i;
}
bool cmp(const node &a,const node &b){
	return a.w<b.w;
}
int find(int x){
	int r=x;
	while(f[r]!=r){
	    r=f[r];
	}
	int temp;
	while(r!=x){
		temp=f[x];
		f[x]=r;
		x=temp;
	}
	return r;
}
int kruskal(int m){
	sort(edge,edge+m,cmp);
	int sum=0;
	for(int i=0;i<m;i++){
		int fx=find(edge[i].u),fy=find(edge[i].v);
		if(fx!=fy){
			f[fx]=fy;
			sum=sum+edge[i].w;
		}

	}
	return sum;
}
int main(){	
	while(scanf("%d",&n)==1&&n!=0){
	    scanf("%d",&m);
		init(n);		
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		printf("%d\n",kruskal(m));

	}
	
	return 0;
}