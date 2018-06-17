#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;
int n;
const int maxn=100;
int origin[maxn][maxn];
int later[maxn][maxn];

int main(){
	int i,j;
	char input[maxn][maxn];
	int min=10000;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++)
		later[0][i]=0;
	for(i=0;i<=n;i++)
		later[i][0]=later[i][n+1]=0;
	
	for(i=1;i<=n;i++)
		 scanf("%s",input[i]);
    for(i=1;i<=n;i++)
		for(j=0;j<n;j++){
		    if(input[i][j]=='w') origin[i][j+1]=1;
			else if(input[i][j]=='y') origin[i][j+1]=0;
		}

	while(later[1][n+1]<1){
		int step=0;
		int flag=1;
		for(i=1;i<n;i++)
		    for(j=1;j<=n;j++)
		    	later[i+1][j]=(origin[i][j]+later[i][j]+later[i-1][j]+later[i][j+1]+later[i][j-1])%2;
	    for(i=1;i<=n;i++){
			if(origin[n][i]!=(later[n][i]+later[n-1][i]+later[n][i-1]+later[n][i+1])%2){
			    flag=0;
				break;
			}
		}
		if(flag==1){
			for(i=1;i<=n;i++)
			    for(j=1;j<=n;j++){
	  		      if(later[i][j]==1) step++; 	
			}
		}
		else step=999999;
		if(step<min)  min=step;
		
	    later[1][1]++;
		int c=1;
		while(later[1][c]>1){
		    later[1][c]=0;
			c++;
			later[1][c]++;
		}
	}
	if(min>=10000)
		cout<<"inf"<<endl;
	else cout<<min<<endl;
	
}