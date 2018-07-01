#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn=200;
int main(){	
	char m[200+10];
	int m1[200+10];
    char n[200+10];
	int n1[200+10];
	int r[maxn*2+10];//结果
	scanf("%s",m);
	scanf("%s",n);
	int lenm=strlen(m);
    int lenn=strlen(n);
	memset(m1,0,sizeof(m1));
	memset(n1,0,sizeof(n1));
	memset(r,0,sizeof(r));
	for(int i=0;i<lenm;i++){
	    m1[lenm-1-i]=m[i]-'0';		
	}
	for(int i=0;i<lenn;i++){
	    n1[lenn-1-i]=n[i]-'0';
	}
	for(int i=0;i<lenn;i++){
		for(int j=0;j<lenm;j++){
		    r[i+j]+=n1[i]*m1[j];  //此处要加上原来的r[i+j]，否则会出错
		}
	}
	for(int i=0;i<maxn*2;i++){
		if(r[i]>=10){
		    r[i+1]+=r[i]/10;
			r[i]=r[i]%10;

		}
	}
	bool bs=false;
	for(int i=maxn*2;i>=0;i--){
	    if(bs)
			printf("%d",r[i]);
		else if(r[i]){
			printf("%d",r[i]);
			bs=true;

		}}
	if(!bs)
		printf("0");

}