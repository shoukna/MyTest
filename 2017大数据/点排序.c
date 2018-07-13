#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 100+5
typedef struct point{
	int a,b;
	int dis;
};
struct point a[maxn];
int compare(const void* m,const void *n){
	return (*(struct point *)m).dis > (*(struct point *)n).dis ? 1 : -1;
}
int main(){
	int x,y,n,i;
	scanf("%d%d",&x,&y);
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d%d",&a[i].a,&a[i].b);
		a[i].dis=(a[i].a-x)*(a[i].a-x)+(a[i].b-y)*(a[i].b-y);
	}
	qsort(a,n,sizeof(struct point),compare);
	for(i=0;i<n;i++){
		if(i==n-1) printf("(%d,%d)\n",a[i].a,a[i].b);
		else printf("(%d,%d),",a[i].a,a[i].b);
	}
}