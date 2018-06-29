#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int compare(const void * p1,const void * p2){
    return * ((int *)p1)- *((int *)p2);
}
int main(){
	int m,n,k;
	scanf("%d",&m);
	int a[1024+10];
	while(m--){
	    scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=100000;
		while(k--){
			int j;
			for(j=n;j>=1&&a[j]<a[j-1];j--);
			if(j>=1){
			    int minlarger=a[j];
				int minIdx=j;
				for(int k=j;k<=n;k++){
					if(a[k]>a[j-1]&&a[k]<minlarger){
						minlarger=a[k];
						minIdx=k;
					}
				}
				a[minIdx]=a[j-1];
				a[j-1]=minlarger;
				qsort(a+j,n-j+1,sizeof(int),compare);

			}
			else{
			    for(int i=1;i<=n;i++)
					a[i]=i;
			}
			
		}
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}