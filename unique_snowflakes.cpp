#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=100;
int a[maxn];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
		    scanf("%d",&a[i]);
	    int L=0,R=0;
	    set<int>s;
	    int ans=0;
	    while(R<n){
	    	while(R<n&&(s.count(a[R])==0)) s.insert(a[R++]);
	    	ans=max(ans,R-L);
	    	s.erase(a[L++]);
	    }
	    printf("%d\n",ans);
	}
	return 0;
}


