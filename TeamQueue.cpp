#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
map<int,int> cnt;
#define maxn 100
int main(){
	int t,kase=0;
	while(scanf("%d",&t)==1&&t){
		printf("Scenario #%d\n",++kase);
 
		map<int,int>team;
		for(int i=0;i<t;i++){
			int n,x;
		    scanf("%d",&n);
			for(int j=0;j<n;j++){
			    scanf("%d",&x);
				team[x]=i;
			}
		}
		queue<int>q,q2[maxn];
		for(;;){
		    char cmd[10];  //不能声明为string cmd，否则不能取首字母
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D'){
			    int m=q.front();
				int mm=q2[m].front();
				printf("%d\n",mm);
				q2[m].pop();
				if(q2[m].empty()) q.pop();
			}
			else if(cmd[0]=='E'){
				int x;
			    scanf("%d",&x);
				int t=team[x];//0,1
				if(q2[t].empty()) q.push(t);
				q2[t].push(x);

			}
		}
		printf("\n");

	}

	return 0;
}
