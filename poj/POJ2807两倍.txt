#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main(){//数组第一个数可以为0！
	int a[20];
	int i=0;
	int p;
	int count=0;
	while(scanf("%d",&p)==1){
		if(p==-1)
			break;
		else{
			count=0;
			a[0]=p;i=1;
			while(scanf("%d",&p)==1){
			    if(p==0) break;
			    else a[i++]=p;
			}
		for(int j=0;j<i;j++){
		    int x=a[j];
		    for(int k=0;k<i;k++)
			    if(a[k]==2*x) count++;
	    }
	    printf("%d\n",count);
	    }
	}
}
