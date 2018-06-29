#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
char n1[]="- -- -----";
char n2[]="|   ||| ||";
char n3[]="|||||  |||";
char n4[]="  ----- --";
char n5[]="| |   | | ";
char n6[]="|| |||||||";
char n7[]="- -- -- --";

int main(){
	int s;
	char sznumber[10];
	while(1){
		scanf("%d %s",&s,sznumber);
		if(s==0) break;
		int length=strlen(sznumber);
		for(int i=0;i<length;i++){
			int m=sznumber[i]-'0';
			printf(" ");
			for(int j=0;j<s;j++){
				printf("%c",n1[m]);
			}
			printf("  ");
		}
		printf("\n");
		for(int j=0;j<s;j++){ 
			for(int i=0;i<length;i++){
				int m=sznumber[i]-'0';
				printf("%c",n2[m]);
				for(int k=0;k<s;k++)
					printf(" "); 
				printf("%c ",n3[m]);//每个数字后面有一列空白
			}
			printf("\n");
		}
		for(int i=0;i<length;i++){
			int m=sznumber[i]-'0';
			printf(" ");
			for(int j=0;j<s;j++){
				printf("%c",n4[m]);
			}
			printf("  ");
		}
		printf("\n");
		for(int j=0;j<s;j++){ 
			for(int i=0;i<length;i++){
				int m=sznumber[i]-'0';
				printf("%c",n5[m]);
				for(int k=0;k<s;k++)
					printf(" ");
				printf("%c ",n6[m]);
			}
			printf("\n");
		}
		for(int i=0;i<length;i++){
			int m=sznumber[i]-'0';
			printf(" ");
			for(int j=0;j<s;j++){
				printf("%c",n7[m]);
			}
			printf("  ");
		}
		printf("\n\n");
	}
}