#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 30
char s1[maxn+5],s2[maxn+5],s3[maxn+5];
int len;
void Swap(char s[],int i){
	s[i-1]=s[i-1]=='1'?'0':'1';
	s[i]=s[i]=='1'?'0':'1';
	if(i+1<len)
		s[i+1]=s[i+1]=='1'?'0':'1';
}

int main(){
	int i,flag,c1,c2,ans1,ans2;
	while(scanf("%s %s",s2,s3)!=EOF){
		c1=0;c2=1;ans1=1e9;ans2=1e9;flag=0;
	    strcpy(s1,s2);
		len=strlen(s1);
		for(i=1;i<len;i++){
			if(s1[i-1]!=s3[i-1]){
		        Swap(s1,i);
			    c1++;		
			}		
		}
		if(strcmp(s1,s3)==0){
		    flag=1;
			ans1=c1;
		}
		strcpy(s1,s2);
		s1[0]=s1[0]=='1'?'0':'1';
		s1[1]=s1[1]=='1'?'0':'1';
		for(i=1;i<len;i++){
			if(s1[i-1]!=s3[i-1]){
		        Swap(s1,i);
			    c2++;		
			}
		}
		if(strcmp(s1,s3)==0){
		    flag=1;
			ans2=c2;
		}
		if(flag){
		    printf("%d\n",min(ans1,ans2));
		}
		else printf("impossible!\n");
	}
}