#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
const int maxn=100;
int main(){
	int t,n;
	int a[maxn+10];
	int num;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		while(!q.empty()){
		    q.pop();
		}
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			q.push(a[i]);
		}
		num=0;
		while(q.size()!=1){
		    int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();
			num+=a+b;
			q.push(a+b);
		}
		printf("%d\n",num);
	}	
}