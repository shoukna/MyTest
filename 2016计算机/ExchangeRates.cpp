#include<cstdio>
#include<cstdlib>
#include<iostream> 
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn=365+5;
double dp[maxn][2];
double deal(double x){   //舍去美分以下的数 
	x*=100.0;
	int y=(int)x;
	return y/100.0;
}
int main(){
	int d;
	double rate;
	while((scanf("%d",&d)==1)&&d){
	    dp[0][0]=1000.0;
		dp[0][1]=0.0;
		for(int i=1;i<=d;i++){
		    scanf("%lf",&rate);
			dp[i][0]=max(dp[i-1][0],deal(dp[i-1][1]*rate*0.97));
			dp[i][1]=max(dp[i-1][1],deal(dp[i-1][0]*0.97/rate));
		}
		printf("%.2lf\n",dp[d][0]);
	}
}