#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn=200;
int subtract(int *p1,int len1,int *p2,int len2){
	if(len1<len2) return -1;
	bool bs=false;
	if(len1==len2){
	    for(int i=len1-1;i>=0;i--){
	        if(p1[i]>p2[i])
		    	bs=true;
		    else if(p1[i]<p2[i]){
		        if(!bs)
		    		return -1;
		    }
	    }
	}
	for(int i=0;i<len1;i++){
	    p1[i]-=p2[i];
		if(p1[i]<0){
		    p1[i]+=10;
			p1[i+1]-=1;
		}
	}
	for(int i=len1-1;i>=0;i--){
	    if(p1[i])
			return i+1;
	}
	return 0;

}
int main(){	
	char m[200+10];
	int m1[200+10];
    char n[200+10];
	int n1[200+10];
	int r[maxn*2+10];//½á¹û
	int nlen1;
	scanf("%s",m);
	scanf("%s",n);
	int lenm=strlen(m);
    int lenn=strlen(n);
	memset(m1,0,sizeof(m1));
	memset(n1,0,sizeof(n1));
	memset(r,0,sizeof(r));
	for(int i=0;i<lenm;i++){
	    m1[lenm-1-i]=m[i]-'0';		
	}
	for(int i=0;i<lenn;i++){
	    n1[lenn-1-i]=n[i]-'0';
	}
	if(lenm<lenn){
	    printf("0\n");
		return 0;
	}
	nlen1=subtract(m1,lenm,n1,lenn);
	if(nlen1<0){
	    printf("0\n");
		return 0;
	}
	else if(nlen1==0){
	    printf("1\n");
		return 0;
	}
	r[0]++;
	int ntimes=nlen1-lenn;
	if(ntimes<0)
		goto OutPutResult;
	else if(ntimes>0){
		for(int i=nlen1-1;i>=0;i--){
		    if(i>=ntimes)
				n1[i]=n1[i-ntimes];
			else n1[i]=0;
		}
	}
	lenn=nlen1;
	for(int j=0;j<=ntimes;j++){
	    int ntemp;
		while((ntemp=subtract(m1,nlen1,n1+j,lenn-j))>=0){
		    nlen1=ntemp;
			r[ntimes-j]++;
		}
	}
	OutPutResult:
	for(int i=0;i<maxn;i++){
		if(r[i]>=10){
		    r[i+1]+=r[i]/10;
			r[i]=r[i]%10;
		}
	}
	bool bs=false;
	for(int i=maxn;i>=0;i--){
		if(bs)
			printf("%d",r[i]);
		else if(r[i]){
			printf("%d",r[i]);
			bs=true;
		}
	}
	if(!bs){
	    printf("0\n");
	}
	printf("\n");
	return 0;
}