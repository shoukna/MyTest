#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
const int maxn=1024;
const int len=32;
char s[maxn];
int buf[len][len],cnt;
using namespace std;
void build(char *s,int &p,int r,int c,int w){
    char ch=s[p++];
	if(ch=='p'){
	    build(s,p,r,c+w/2,w/2);
		build(s,p,r,c,w/2);
		build(s,p,r+w/2,c,w/2);
		build(s,p,r+w/2,c+w/2,w/2);
	}
	else if(ch=='f'){
		for(int i=r;i<r+w;i++){
			for(int j=c;j<c+w;j++){
				if(buf[i][j]==0){buf[i][j]=1;cnt++;}
			}
		}
	}
}
int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		cnt=0;
		for(int i=0;i<2;i++){
		    scanf("%s",s);
			int p=0;
			build(s,p,0,0,len);
		}
		printf("%d\n",cnt);
	}
	return 0; 
}
