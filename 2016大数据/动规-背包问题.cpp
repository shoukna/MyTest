#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#define maxn 3402
#define maxm 12880
using namespace std;
int main(){
	int N,M;
	int w[maxn],v[maxm];
	int dp[maxm];
	while(scanf("%d%d",&N,&M)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++){
		    scanf("%d%d",&w[i],&v[i]);
		}
		for(int i=0;i<N;i++){
			for(int j=M;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		printf("%d\n",dp[M]);

	}

}