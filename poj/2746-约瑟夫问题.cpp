#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int main(){
	int n,m;
	int a[300+5];
	while(scanf("%d%d",&n,&m)==2&&n!=0&&m!=0){
		int i,j;
		int count=0;
	    for(int i=0;i<n;i++)
			a[i]=1;
		int nptr=0;
		for(int i=0;i<n;i++){
		    count=0;
			while(count<m){
				while(a[nptr]==0) nptr=(nptr+1)%n;
				count++;
				nptr=(nptr+1)%n;
			}
			nptr--;
			if(nptr<0) nptr=n-1; 
			if(i==n-1) {
			    printf("%d\n",nptr+1);
			}
			a[nptr]=0;

		}

	}
}
