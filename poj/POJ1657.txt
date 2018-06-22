#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
using namespace std;

int main(){
	int ncases;
	int xd,yd;
	int d1,d2,d3,d4;
	char begin[5],end[5];
	scanf("%d",&ncases);
	while(ncases--){
	    scanf("%s",begin);
		scanf("%s",end);
		xd=abs(begin[0]-end[0]);
		yd=abs(begin[1]-end[1]);
		if(xd==0&&yd==0){ d1=d2=d3=d4=0; printf("0 0 0 0\n");}
		else{
		    if(xd<yd)  printf("%d ",yd);
			else printf("%d ",xd);
			if(xd==0||yd==0||xd==yd) printf("1 ");
			else printf("2 ");
			if(xd==0||yd==0) printf("1 ");
			else printf("2 ");
			if(abs(yd-xd)%2!=0) printf("Inf\n");
			else{
				if(xd==yd) printf("1\n");
				else printf("2\n");

		}
		
	}
	}
	return 0;

}