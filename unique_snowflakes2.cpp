#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=100;
map<int,int>cur;
int a[maxn],last[maxn];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&n);
		cur.clear();
	    for(int i=0;i<n;i++){
		    scanf("%d",&a[i]);
			if(cur.count(a[i])==0) last[i]=-1;
			else last[i]=cur[a[i]];
			cur[a[i]]=i;
		}
	    int ans=0;
		int L=0,R=0;
		while(R<n){
		    while(R<n&&last[R]<L) R++;
			ans=max(ans,R-L);
			L++;
		}
	    printf("%d\n",ans);
	}
	return 0;
}
