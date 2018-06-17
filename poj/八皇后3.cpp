#include<cstdlib>
#include<cstdio>
using namespace std;
int queenPlaces[92][8];
int num;
int hang[8];
void queen(int i){
	int k;
	int j;
	if(i==8){
		for(k=0;k<8;k++) queenPlaces[num][k]=hang[k]+1;
		num++;
		return;
	}
	for(j=0;j<8;j++){
		for(k=0;k<i;k++){
			if(j==hang[k]||j-hang[k]==i-k||hang[k]-j==i-k) break;
		}
			if(k==i){
				hang[i]=j;
			    queen(i+1);
			}
}
}
int main(){
	int n;
	int b;
	queen(0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&b);
		for(int j=0;j<8;j++)
			printf("%d ",queenPlaces[b-1][j]);
		printf("\n");
	}
}