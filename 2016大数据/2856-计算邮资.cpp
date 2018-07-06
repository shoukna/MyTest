#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	double w;
	char ch;
	double totalm;
	int totalw;
	totalw=0;
	totalm=0.0;
	while(scanf("%lf %c",&w,&ch)!=EOF){
	if(w<=1){
	    if(ch=='y')
			totalm=0.8+2;
		else if(ch=='n') totalm=0.8;
	}
	else if(w>1){
		w=w-1; //”√ceil»°’˚¥ÌŒÛ
		if(ch=='y')
			totalm=0.8+w*0.5+2;
		else if(ch=='n') totalm=0.8+w*0.5;
	}
	printf("%g\n",totalm);
	}
}