#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000;
char sz1[maxn];
char sz2[maxn];
int aMaxLen[maxn][maxn];
int main(){
	while(scanf("%s%s",sz1+1,sz2+1)>0){
	    int len1=strlen(sz1+1);
		int len2=strlen(sz2+1);
		for(int i=1;i<=len1;i++)
			aMaxLen[i][0]=0;
		for(int i=2;i<=len2;i++)
			aMaxLen[0][i]=0;
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++){
				if(sz1[i]==sz2[j])
					aMaxLen[i][j]=aMaxLen[i-1][j-1]+1;
				else {
					aMaxLen[i][j]=max(aMaxLen[i-1][j],aMaxLen[i][j-1]);
				}
			}
			printf("%d\n",aMaxLen[len1][len2]);
	}
	return 0;

}