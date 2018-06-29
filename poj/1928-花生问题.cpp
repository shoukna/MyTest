#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn=55;
int a[maxn][maxn];
int main(){
	int T;
	int M,N,K;
	scanf("%d",&T);
	while(T--){
	    scanf("%d%d%d",&M,&N,&K);
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
				scanf("%d",&a[i][j]);
		int totalt=0,nmax=0,maxi=0,maxj=0;
		int totaln=0;
		int curi=0,curj=0;
		while(totalt<K){
			    nmax=0;
				for(int i=1;i<=M;i++)
					for(int j=1;j<=N;j++){
						if(nmax<a[i][j]){
						    nmax=a[i][j];
							maxi=i;
							maxj=j;
						}
					}
					if(nmax==0) break;
					if(curi==0) curj=maxj;
					if((totalt+1+maxi+abs(maxi-curi)+abs(maxj-curj))<=K){
					    totalt=totalt+1+abs(maxi-curi)+abs(maxj-curj);
						totaln=totaln+nmax;
						curi=maxi;
						curj=maxj;
						a[maxi][maxj]=0;
					}
					
					else break;
					
	}
		printf("%d\n",totaln);
	}
}