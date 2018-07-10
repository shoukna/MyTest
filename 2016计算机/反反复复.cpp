#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=200;
const int maxr=100;
const int maxc=20;

int main(){
	char ch[maxr+5][maxc+5];
	char s[maxn+5];
	int col;
	scanf("%d",&col);
	scanf("%s",s);
	int len=strlen(s);
	int row=ceil((double)len/col);
	int k=0,j;
	for(int i=0;i<row;i++){
		if(i%2==0){
		    for(j=0;j<col;j++){
				ch[i][j]=s[k++];
			}
		}
		else{
		    for(j=col-1;j>=0;j--){
				ch[i][j]=s[k++];	
			}
		}
	}
	for(int j=0;j<col;j++)
		for(int i=0;i<row;i++)
			printf("%c",ch[i][j]);
	printf("\n");
}