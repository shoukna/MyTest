#include<cstdlib>
#include<cstdio>
using namespace std;
int queenPlaces[92][8];
int count=0;
int board[8][8];
void putQueen(int ithqueen);
int main(){
	int n;
	int ith;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)
			board[i][j]=-1;
		for(int j=0;j<92;j++)
			queenPlaces[j][i]=0;
	}
	putQueen(0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&ith);
		for(int j=0;j<8;j++)
			printf("%d ",queenPlaces[ith-1][j]);
		printf("\n");
	}

}
void putQueen(int ithqueen){
	int i,k,r;
	if(ithqueen==8){
	    count++;
		return;
	}
	for(i=0;i<8;i++){
		if(board[i][ithqueen]==-1){
			 board[i][ithqueen]=ithqueen;
			 for(k=count;k<92;k++)
				 queenPlaces[k][ithqueen]=i+1;
			 for(k=0;k<8;k++)
				 for(r=0;r<8;r++){
					 if(board[k][r]==-1&&(k==i||r==ithqueen||abs(k-i)==abs(r-ithqueen)))
						 board[k][r]=ithqueen;
				 }
			putQueen(ithqueen+1);
			for(k=0;k<8;k++)
				for(r=0;r<8;r++)
					if(board[k][r]==ithqueen) board[k][r]=-1;
		} 

	}

}