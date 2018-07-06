#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=10;
int a[maxn+1][maxn+1];
int main(){
	int n;
	scanf("%d",&n);
	int x=1;
	int k=1;
	for(int i=0;i<2*n;i++){
		if((i%2==0&&i<n)){
			for(int j=0;j<=i;j++){
				a[i-j][j]=x;
				x++;
			}
		}
		if(i%2!=0&&i<n){
			for(int j=0;j<=i;j++){
			    a[j][i-j]=x;
				x++;
			}
		}
		if(i%2==0&&i>=n){
			for(int j=0;j<2*n-1-i;j++){
			    a[i-j-k][j+k]=x;
				x++;
				
			}	
			k++;
		}
		if(i%2!=0&&i>=n){
			for(int j=0;j<2*n-1-i;j++){
			    a[j+k][i-j-k]=x;
				x++;
				
			}
			k++;
		}


		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}