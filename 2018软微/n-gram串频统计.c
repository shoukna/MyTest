#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define maxn 500+10
char s[maxn];
int m[maxn];
int main(){	
	int n,k;
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	memset(m,0,sizeof(m));
	for(int i=0;i<=len-n;i++){
		m[i]=1;
		for(int j=i+1;j<=len-n+1;j++){
			if(s[i]==s[j]){
				for(k=1;k<n;k++){
				    if(s[i+k]!=s[j+k]) break;
				}
				if(k!=n) break;
				m[i]++;
			}
		}
	}
	int maxnum=0;
	for(int i=0;i<maxn;i++){
		if(maxnum<m[i]){
		    maxnum=m[i];
		}
	}
	if(maxnum<=1) printf("NO\n");
	else{
	    printf("%d\n",maxnum);
	    for(int i=0;i<maxnum;i++){
		    if(m[i]==maxnum){
		    	for(int j=0;j<n;j++){
		    	     printf("%c",s[i+j]);
		    	}
		    	printf("\n");
		    }
	    }
	}
	return 0;
}
