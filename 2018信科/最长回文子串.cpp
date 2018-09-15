#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 100+5
char str[maxn];
int main(){	
	int n;
	scanf("%d",&n);
	while(n--){
	    scanf("%s",str);
		int len=strlen(str);
		int maxStr=0;
		int startMax=0;
		int temp=0;
		for(int i=0;i<len;i++){
			for(int j=0;i-j>=0&&i+j<len;j++){
			    if(str[i-j]!=str[i+j])
					break;
				temp=2*j+1;
			}
			if(temp>maxStr){
				startMax=i;
				maxStr=temp;
			}
			for(int j=0;i-j>=0&&i+j+1<len;j++){
			    if(str[i-j]!=str[i+j+1])
					break;
				temp=2*j+2;
			}
			if(temp>maxStr){
				startMax=i;
				maxStr=temp;
			}
		}
			if(maxStr%2==0){
				startMax=startMax-maxStr/2+1;
				for(int k=startMax;k<startMax+maxStr;k++)
					printf("%c",str[k]);
			}
			else{
			    startMax=startMax-maxStr/2;
				for(int k=startMax;k<startMax+maxStr;k++)
					printf("%c",str[k]);
			}
			printf("\n");

		}

	
	return 0;
}
