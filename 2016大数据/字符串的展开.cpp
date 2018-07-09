#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int p1,p2,p3;
	char s[100+5];
	scanf("%d%d%d",&p1,&p2,&p3);
	scanf("%s",s);
	int len=strlen(s);
	char ca,cb;
	int d;
	for(int i=0;i<len;i++){
		if(s[i]=='-'){
		    ca=s[i-1];
			cb=s[i+1];
		if(ca<cb&&((ca>='a'&&ca<='z')||(ca>='0'&&ca<='9'))&&((cb>='a'&&cb<='z')||(cb>='0'&&cb<='9'))){
			if(p1==1){
			    if(ca>='A'&&ca<='Z')ca=ca+32;
				if(cb>='A'&&cb<='Z')cb=cb+32;
			}
			if(p1==2){
			    if(ca>='a'&&ca<='z')ca=ca-32;
				if(cb>='a'&&cb<='z')cb=cb-32;
			}	
			if(p3==1){
				for(int j=ca+1;j<cb;j++){
					d=j;
				    if(p1==3) d='*';
					for(int k=1;k<=p2;k++) printf("%c",d);
				}
			}
			if(p3==2){
				for(int j=cb-1;j>ca;j--){
					d=j;
				    if(p1==3) d='*';
					for(int k=1;k<=p2;k++) printf("%c",d);
				}
			}
		}
		else printf("-");
		}
			else printf("%c",s[i]);
			
			

		}
	printf("\n");
	
}