//代码提交一直错误，原因1：maxn设置得不够大（题目说明最多有1000个平台，所以应该设置为1000）；原因2：aPlatform、aLeft和aRight数组未设置更大的空间（未加10，不一定加10，加1也可以）
#include<stdio.h>
#include<memory.h>
#include<stdlib.h> 
#define MAXH 1000000
int t,n,x,y,h,MAX;
const int maxn=1000;
struct Platform{
    int Lx,Rx,h;
};
Platform aPlatform[maxn+10];
int aLeft[maxn+10];
int aRight[maxn+10];
int MyCompare(const void * p1,const void * p2){
	Platform *e1,*e2;
	e1=(Platform *)p1;
	e2=(Platform *)p2;
	return e2->h - e1->h;
}
int MinTime(int L,bool bleft){
	int y=aPlatform[L].h;
	int x,i=0;
	if(bleft) 
		x=aPlatform[L].Lx;
	else x=aPlatform[L].Rx;
	for(i=L+1;i<=n;i++)
		if(aPlatform[i].Lx<=x&&aPlatform[i].Rx>=x)
			break;
	if(i<=n){
		if((y-aPlatform[i].h)>MAX)
			return MAXH;
	}
	else{
		if(y>MAX)
			return MAXH;
		else return y;			
	}
		int nLeftTime=y-aPlatform[i].h+x-aPlatform[i].Lx;
		int nRightTime=y-aPlatform[i].h+aPlatform[i].Rx-x;
		if(aLeft[i]==-1)
			aLeft[i]=MinTime(i,true);
		if(aRight[i]==-1)
			aRight[i]=MinTime(i,false);
		nLeftTime+=aLeft[i];
		nRightTime+=aRight[i];
		if(nLeftTime<nRightTime) return nLeftTime;
		return nRightTime;
}
int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    scanf("%d%d%d%d",&n,&x,&y,&MAX);
		memset(aLeft,-1,sizeof(aLeft));
		memset(aRight,-1,sizeof(aRight));
		aPlatform[0].Lx=x;
		aPlatform[0].Rx=x;
		aPlatform[0].h=y;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&aPlatform[i].Lx,&aPlatform[i].Rx,&aPlatform[i].h);  
		qsort(aPlatform,n+1,sizeof(Platform),MyCompare);
		printf("%d\n",MinTime(0,true));
	} 

	return 0;

}