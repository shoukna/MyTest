#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxd=20;
int s[1<<maxd-1];
int main(){
	int D,I;
	int num=1;
	while(scanf("%d%d",&D,&I)==2){
		memset(s,0,sizeof(s));
		int n=(1<<D)-1;		
		while(I--){
			num=1;
			for(;;){
				s[num]=!s[num];
				if(s[num]) num=num*2;
			    else num=num*2+1;
			    if(num>n) break;
			}
	    }
		printf("%d\n",num/2);
	}
	
	return 0;
}
