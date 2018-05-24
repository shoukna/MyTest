#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int k,x;
	int kase;
	while(scanf("%d",&k)==1&&k){
		kase=0;
		for(int y=1;y<=2*k;y++){
			if(y==k) continue;
			if(y!=k){
			    x=(k*y)/(y-k);
			    if(x>=y&&(k==(x*y/(x+y)))) {
			        printf("1/%d = 1/%d + 1/%d\n",k,x,y);
				    kase++;
			    }
		
			}
		}
		printf("%d\n",kase);
	}
	return 0; 
}
