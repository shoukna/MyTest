#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define maxn 80+5
char str[maxn];
int alph[26+1];
int main(){	
	memset(alph,0,sizeof(alph));
	for(int i=0;i<4;i++){
	    gets(str);
		for(int j=0;j<strlen(str);j++){
			if(str[j]>='A'&&str[j]<='Z'){
			    alph[str[j]-'A']++;
			}
		}
	}
	int maxnum=0;
	for(int i=0;i<26;i++){
		if(maxnum<alph[i]){
			maxnum=alph[i];
		}
	}
	for(int i=0;i<maxnum;i++){
	    for(int j=0;j<26;j++){
			if(maxnum-i<=alph[j]){
			    printf("* ");
			}
			else printf("  ");
		}
		printf("\n");
	}
	for(char c='A';c<='Z';c++)
		printf("%c ",c);
	printf("\n");

	return 0;
}
