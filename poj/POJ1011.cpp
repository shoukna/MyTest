#include<cstdlib>
#include<cstdio>
using namespace std;
int sticks[100];
bool used[100];
int compare(const void* arg1,const void* arg2){
	return *(int *)arg2-*(int*)arg1;
}
bool con(int totalSticks,int unusedSticks,int left,int len){
	if(unusedSticks==0&&left==0) return true;
	if(left==0) left=len;
	for(int i=0;i<totalSticks;i++){
		if(used[i]==true) continue;
		if(sticks[i]>left) continue;
		used[i]=true;
		if(con(totalSticks,unusedSticks-1,left-sticks[i],len))
			return true;
		used[i]=false;
		if(left==len||sticks[i]==left)
			break;
	}
	return false;
	
}

int main(){
	int n;
	int sum;
	while(scanf("%d",&n)==1&&n!=0){
		sum=0;
	    for(int i=0;i<n;i++){
			scanf("%d",&sticks[i]);
			used[i]=false;
			sum=sum+sticks[i];
		}
		qsort(sticks,n,sizeof(int),compare);
		for(int i=sticks[0];i<=sum;i++){
		    if(sum%i!=0) continue;
			if(con(n,n,0,i)){
			    printf("%d\n",i);
				break;
			}		
		}
	}
}