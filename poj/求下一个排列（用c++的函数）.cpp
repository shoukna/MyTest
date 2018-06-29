#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int m,n,k;
	scanf("%d",&m);
	int a[1024+10];
	while(m--){
	    scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<k;i++)
		    next_permutation(a,a+n);
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}