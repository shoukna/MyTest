#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
using namespace std;
const int maxn=18+5;

int main(){
	int n;
	int a[maxn];
	
	while(scanf(%d,&n)==1&&n){
		long long ans=0;
		for(int i=0;in;i++){
		    scanf(%d,&a[i]);
		}
		for(int i=1;i=n;i++){   子序列长度
			for(int j=0;j+i=n;j++){
			    long long tt=1;
				for(int k=j;kj+i;k++){   子序列从j开始
				    tt=tta[k];
				}
				ans=max(ans,tt);
			}
		}
		printf(%dn,ans);

	}
	return 0; 
}
