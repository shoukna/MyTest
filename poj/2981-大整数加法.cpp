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
	int c[200+10];//进位
	int r[200+10];//结果
	scanf("%s",m);
	scanf("%s",n);
	int lenm=strlen(m);
    int lenn=strlen(n);
	memset(m1,0,sizeof(m1));
	memset(n1,0,sizeof(n1));
	memset(c,0,sizeof(c));
	memset(r,0,sizeof(r));
	for(int i=0;i<lenm;i++){
	    m1[lenm-1-i]=m[i]-'0';		
	}
	for(int i=0;i<lenn;i++){
	    n1[lenn-1-i]=n[i]-'0';
	}
	/*
	int i;
	for(i=0;;i++){
		int a;
		int len=(lenm>lenn)?lenm:lenn;
		if(i>=len+1) {
		    break;
		}
		if(lenm==lenn) {
		    if(i==0) a=m1[i]+n1[i];
		    else a=m1[i]+n1[i]+c[i-1];
		}
		else if(len==lenn&&i>=lenm) {
		    a=n1[i]+c[i-1];
		}
		else if(len==lenm&&i>=lenn){
		    a=m1[i]+c[i-1];
		}
		if(a>=10){
		    c[i]=1;
			r[i]=a-10;
		}
		else {
		    c[i]=0;
			r[i]=a;
		}
	}
	
	bool bs=false;	
	for(int j=i-1;j>=0;j--){
		if(bs)
			printf("%d",r[j]);
		else if(r[j]){
		    printf("%d",r[j]);
			bs=true;
		}
	}
	if(!bs)
		cout<<"0";
	*/
	
	
	for(int i=0;i<maxn;i++){
	    r[i]=r[i]+m1[i]+n1[i];
		if(r[i]>=10){
		    r[i]-=10;
			r[i+1]++;
		}
	}
	
	bool bs=false;
	for(int i=maxn;i>=0;i--){
	    if(bs)         //跳过前面为0的
			printf("%d",r[i]);
		else if(r[i]){
		    printf("%d",r[i]);
			bs=true;
		}
	}
	if(!bs)
		cout<<"0";

}