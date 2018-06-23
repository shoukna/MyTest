#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
using namespace std;
long ba(char *a,int b){
	int idx=strlen(a);
	int req=0;
	for(int j=0;j<idx;j++){
		if(a[j]-'0'>=b) return -1;
		req=req+(a[j]-'0')*pow(b,idx-j-1);

	}
	return (long)req;
}
int main(){
	char p[20],q[20],r[20];
	int T;
	int i;
	long pl,ql,rl;
	scanf("%d",&T);
	while(T--){
	    scanf("%s%s%s",p,q,r);
		for(i=2;i<=16;i++){
		     pl=ba(p,i);
			 ql=ba(q,i);
			 rl=ba(r,i);
			 if(pl!=-1&&ql!=-1&&rl!=-1){
			     if(pl*ql==rl){
					 printf("%d\n",i);
					 break;
				 }
			 }

		}
		if(i==17)
			printf("0\n");
	}
}
