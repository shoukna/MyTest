#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	char s[1000+5];//���������
	int a[26];//��Ӧ��26��Ӣ����ĸ����
	int count;
	char ch;
	
	while(n--){
	    scanf("%s",s);
		memset(a,0,sizeof(a));
		count=0;
		for(int i=0;i<strlen(s);i++){
		    a[s[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(a[i]>count) {count=a[i];ch=i+'a';}
		}
		printf("%c %d\n",ch,count);
	}
}
