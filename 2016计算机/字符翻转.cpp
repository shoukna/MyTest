#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h> //C语言中使用strlen要声明该头文件 
using namespace std;
const int maxn=500;

int main(){
	char s[maxn+10];
	gets(s);
	int len=strlen(s);
	s[len]=' ';
	int i,j,k=0;
	for(i=0;i<=len;i++){
		if(s[i]==' '){
			for(j=i-1;j>=k;j--){
			    printf("%c",s[j]);
			}
			if(i!=len) printf(" ");
			j=i;
			k=j+1;
			
		}
	}
	printf("\n");
}