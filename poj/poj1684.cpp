#include<cstdio>
#include<cstdlib>
using namespace std;
int sep(int m,int n){
	if(n==1||m==0) return 1;
	if(n>m) return sep(m,m);
	return sep(m,n-1)+sep(m-n,n);
}
int main(){
	int t,m,n;
	int res;
	scanf("%d",&t);
	while(t--){
	    scanf("%d%d",&m,&n);
		res=sep(m,n);
		printf("%d\n",res);
	}
}
