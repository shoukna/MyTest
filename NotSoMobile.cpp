#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
using namespace std;
bool solve(int& w){
	int w1,d1,w2,d2;
	bool b1=true,b2=true;
	cin>>w1>>d1>>w2>>d2;
	if(!w1) b1=solve(w1);
	if(!w2) b2=solve(w2);
	w=w1+w2;
	return b1&&b2&&(w1*d1==w2*d2);
 }
int main(){
	int T;
	int w=0;
	scanf("%d",&T);
	while(T--){
		if(solve(w)) printf("YES\n");else printf("NO\n");
		printf("\n");
	}
	return 0; 
}
