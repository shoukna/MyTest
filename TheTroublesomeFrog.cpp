
#define _CRT_SECURE_NO_DEPRECATE
#include<cstdlib>
#include<cstdio>
using namespace std;
struct PLANT{
	int x,y;
};
PLANT plants[5001];
int r,c,n;
int myCompare(const void* ele1,const void* ele2);
int searchPath(PLANT plt,int dx,int dy);
int main(){
	int max=2;
	int step;
	scanf("%d%d",&r,&c);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&plants[i].x,&plants[i].y);
	qsort(plants,n,sizeof(PLANT),myCompare);
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++){
			int dx=plants[j].x-plants[i].x;
			int dy=plants[j].y-plants[i].y;
			int px=plants[i].x-dx;
			int py=plants[i].y-dy;
			if(px<=r&&px>=1&&py<=c&&py>=1)
				continue;
			if(plants[i].x+max*dx>r)
				break;
			py=plants[i].y+max*dy;
			if(py>c||py<1)
				continue;
			step=searchPath(plants[j],dx,dy);
			if(step>max) max=step;
		}
	if(max==2) max=0;
	printf("%d\n",max);
}
int myCompare(const void *ele1,const void *ele2){
	PLANT *p1;
	PLANT *p2;
	p1=(PLANT*)ele1;
	p2=(PLANT*)ele2;
	if(p1->x == p2->x) return(p1->y - p2->y);
	return(p1->x - p2->x);
}
int searchPath(PLANT plt,int dx,int dy){
	PLANT plant;
	int steps;
	plant.x=plt.x+dx;
	plant.y=plt.y+dy;
	steps=2;
	while(plant.x<=r&&plant.x>=1&&plant.y<=c&&plant.y>=1){
		if(!bsearch(&plant,plants,n,sizeof(PLANT),myCompare)){
		    steps=0;
			break;	 
		}		
		steps++;
		plant.x+=dx;
		plant.y+=dy;
	}	
		return steps;
	
}

