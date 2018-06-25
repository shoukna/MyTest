#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
using namespace std;
char s[100][101];
int t,n;

int search(char * source){
	int subl=strlen(source),slen=strlen(source);
	char sub[101],rev[101];
	bool found;
	while(subl>0){
		for(int i=0;i<=slen-subl;i++){
			strncpy(sub,source+i,subl);
			strncpy(rev,source+i,subl);
			sub[subl]=rev[subl]='\0';
			_strrev(rev);
			found=true;
			for(int j=0;j<n;j++){
				if(strstr(s[j],sub)==NULL&&strstr(s[j],rev)==NULL){
				    found=false;
					break;
				}
			}
			if(found) return subl;
		 }
		subl--;
	}
	return 0;
}
int main(){
	char st[101];
	scanf("%d",&t);
	while(t--){
		int minLen=100;
	    scanf("%d",&n);
		for(int i=0;i<n;i++){
		    scanf("%s",s[i]);
			if(strlen(s[i])<minLen){
				minLen=strlen(s[i]);
				strcpy(st,s[i]);
			}
		}
		int len=search(st);
		printf("%d\n",len);

	}
}
