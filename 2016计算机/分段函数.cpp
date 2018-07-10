#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	double x,y;
	while(scanf("%lf",&x)!=EOF){
		if(x>=0&&x<5){
			y=x*(-1)+2.5;
		}
		else if(x>=5&&x<10){
		    y=2-1.5*(x-3)*(x-3);
		}
		else if(x>=10&&x<20){
		    y=x/2-1.5;
		}
		printf("%.3f\n",y);
	}
}