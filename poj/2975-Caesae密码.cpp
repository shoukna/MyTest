#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
using namespace std;
void decipher(char * s){
    char ch[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
	char end[201];
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(isalpha(s[i]))
		    s[i]=ch[s[i]-'A'];
		else s[i]=s[i];
	}
	gets(end);
}
int main(){
	char s[201];
	gets(s);
	while(strcmp(s,"START")==0){
	    decipher(s);
		printf("%s\n",s);
		gets(s);
		if(strcmp(s,"ENDOFINPUT")==0) break;
	}
}