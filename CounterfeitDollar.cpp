#include<cstdio>
#include<string>
using namespace std;
char le[3][7],rig[3][7],result[3][7];
bool isLight(char c){
	for(int i=0;i<3;i++){
		switch(result[i][0]){
		    case 'u': if(strchr(rig[i],c)==NULL) return false;break;
		    case 'e': if(strchr(rig[i],c)!=NULL||strchr(le[i],c)!=NULL) return false;break;
		    case 'd': if(strchr(le[i],c)==NULL) return false;break;
		}
	}
	return true;
}
bool isHeavy(char c){
	for(int i=0;i<3;i++){
		switch(result[i][0]){
		    case 'u': if(strchr(le[i],c)==NULL) return false;break;
		    case 'e': if(strchr(rig[i],c)!=NULL||strchr(le[i],c)!=NULL) return false;break;
		    case 'd': if(strchr(rig[i],c)==NULL) return false;break;
		}
	}
	return true;
}

int main(){
	int n;
	char c;
	scanf("%d",&n);
	while(n>0){
		for(int i=0;i<3;i++)
			scanf("%s %s %s",&le[i],&rig[i],&result[i]);
		for(c='A';c<='L';c++){
		    if(isLight(c)){
				printf("%c is the counterfeit and light\n",c);
				break;}
		    if(isHeavy(c)){
				printf("%c is the counterfeit and heavy\n",c);
				break;}
		}
		n--;
	}
}
