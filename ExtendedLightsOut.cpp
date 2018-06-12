#include<cstdio>
#include<string>
using namespace std;
int puzzle[6][8],press[6][8];
bool guess(){
	for(int i=1;i<5;i++)
		for(int j=1;j<7;j++)
			press[i+1][j]=(press[i-1][j]+press[i][j]+press[i][j-1]+press[i][j+1]+puzzle[i][j])%2;
	for(int i=1;i<7;i++)
		if(press[5][i]!=((press[4][i]+press[5][i-1]+press[5][i+1]+puzzle[5][i])%2))
			return false;
	return true;

}
void decide(){
	int c;
	for(int i=1;i<7;i++)
		press[1][i]=0;
	while(guess()==false){
	    press[1][1]++;
		c=1;
		while(press[1][c]>1){
		    press[1][c]=0;
			c++;
			press[1][c]++;
		}
	}
}
int main(){
	int kase;
	scanf("%d",&kase);
	for(int i=0;i<7;i++)
		press[0][i]=0;
	for(int i=0;i<6;i++)
		press[i][0]=press[i][7]=0;

	for(int k=0;k<kase;k++){
		for(int i=1;i<6;i++)
		    for(int j=1;j<7;j++)
			    scanf("%d",&puzzle[i][j]);
	    decide();
		printf("PUZZLE #%d\n",k+1);
		for(int i=1;i<6;i++){
			for(int j=1;j<7;j++)
				printf("%d ",press[i][j]);
			printf("\n");
		}
	}
}
