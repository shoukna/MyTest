#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 100+5
int m[maxn],p[maxn],dp[maxn];
int main(){
	int t,n,k,i,j,max=0;
	scanf("%d",&t);
	while(t--){
	    scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&p[i]);
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);
		memset(dp,0,sizeof(dp));
		dp[0]=m[0];
		for(i=1;i<n;i++){
			dp[i]=m[i];
			for(j=0;j<i;j++){
			    if(p[i]-p[j]>k)
					dp[i]=max(dp[i],dp[j]+m[i]);
			}
		}
		max=0;
		for(i=0;i<n;i++){
		    if(dp[i]>max) max=dp[i];
		}
		printf("%d\n",max);

	}
}