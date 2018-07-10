#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn=10000;
void build(int len,char s1[],char s2[]){
    if(len==0) return;
	int p=strchr(s2,s1[0])-s2;
	build(p,s1+1,s2);
	build(len-p-1,s1+p+1,s2+p+1);
	printf("%c",s1[0]);
}

int main(){
	char s1[maxn+5],s2[maxn+5];
	while(scanf("%s %s",s1,s2)!=EOF){
	    int len=strlen(s1);
	    build(len,s1,s2);
            printf("\n");
	}
}