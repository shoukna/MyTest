#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
using namespace std;
const int maxn=100000;
char map[]="22233344455566677778889999";//注意有4个7和9，因为还有Q和Z
char tel[maxn][9];
char str[80];
void stand(int n){
    int j,k;
	j=k=-1;
	while(k<8){
	    j++;
		if(str[j]=='-') continue;
		k++;
		if(k==3){ tel[n][3]='-';k++;}
		if(str[j]>='A'&&str[j]<='Z'){
		    tel[n][k]=map[str[j]-'A'];
		    continue;	
		}
		tel[n][k]=str[j];

	}
	tel[n][k]='\0';
	return;
}
int compare(const void * p1,const void * p2){
	return(strcmp((char*)p1,(char*)p2));
 }
int main(){
	int t,i;
	int count=0;
	bool nod=true;
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    scanf("%s",str);
	    stand(i);
	}
	qsort(tel,t,9,compare);
	i=0;
	while(i<t){
	    int j=i;
		i++;
		while(i<t&&strcmp(tel[i],tel[j])==0) i++;
		if(i-j>1){
		    printf("%s %d\n",tel[j],i-j);
			nod=false;
		}
	}


	if(nod) printf("No duplicates.\n");
}
