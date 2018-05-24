#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
#include<map>
using namespace std;
const int maxn=1000;
map<int,int> mp;

int main(){
	int n;
	while(scanf("%d",&n)==1&&(n<=79)&&(n>=2)){
		int m=0;
		for(int i=01234;i<50000;i++){
			for(int j=0;j<10;j++){
				mp[j]=0;
			}
		    m=i*n;
			int k=0;

			int a1=i/10000;
			int a2=(i-a1*10000)/1000;
			int a3=(i-a1*10000-a2*1000)/100;
			int a4=(i-a1*10000-a2*1000-a3*100)/10;
            int a5=i%10;
			
			int b1=m/10000;
			int b2=(m-b1*10000)/1000;
			int b3=(m-b1*10000-b2*1000)/100;
			int b4=(m-b1*10000-b2*1000-b3*100)/10;
            int b5=m%10;
			mp[a1]++;mp[a2]++;mp[a3]++;mp[a4]++;mp[a5]++;mp[b1]++;mp[b2]++;mp[b3]++;mp[b4]++;mp[b5]++;
			
			for(k=0;k<10;k++){
				if(mp[k]!=1) break;
			}
			if(k==10)  printf("%d / %05d = %d\n",m,i,n);
		}
	}
	return 0; 
}
