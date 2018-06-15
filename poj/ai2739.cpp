#include<cstdlib>
#include<cstdio>
#include<algorithm>
int main(){
	double a,b;
	scanf("%lf%lf",&a,&b);
	int x=(int)(log10(b)/log10(a));
	printf("%d\n",x);
	return 0;
}


