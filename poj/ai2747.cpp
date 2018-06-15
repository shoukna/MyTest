#include<cstdio>
using namespace std;
int main(){
	int n;
	int sum=0;
	int max=0;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if((i+j)%2==0){
				for(int k=0;k<=n;k++){
					if((j+k)%3==0&&(i+j+k)%5==0){
					    sum=i+j+k;
						max=(max>sum)?max:sum;
					}
						
				}
			}
		}
	}
		printf("%d",max);	
}
