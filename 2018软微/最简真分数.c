#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define maxn 600+10
int a[maxn];

int main(){	
	int n,i,j;
	int count=0,m=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	      scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			m=0;
		    int minn;
			if(a[i]<a[j]) minn=a[i];
			else minn=a[i];
			for(int k=2;k<=minn;k++){
				if(a[i]%k==0&&a[j]%k==0) {
					m=1;
					break;
				}
			}		
			if(m==0) count++; 
		}
	}
	printf("%d\n",count);
	return 0;
}
