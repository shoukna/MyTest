//本来以为此题很简单，结果忽略了时间复杂度，应该用归并排序先排序
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 200000
#define maxm 10000000
int s[maxn];
long long sum=0;
int temp[maxm];
void merge(int *s,int *temp,int startIndex,int endIndex,int mid){
    int i=startIndex,j=mid+1,k=startIndex;
	int pointer=startIndex;

	while(i<=mid&&j<=endIndex){
		if(s[i]>s[j]){
		    temp[k]=s[j];
			while(s[pointer]<=2*s[j]&&pointer<=mid)
				pointer++;
			if(pointer!=mid+1)
				sum+=mid-pointer+1;
			j++;
		}
		else{
		    temp[k]=s[i];
			i++;
		}
		k++;
	}
	while(i<=mid)
		temp[k++]=s[i++];
	while(j<=endIndex)
		temp[k++]=s[j++];
	for(int i=startIndex;i<=endIndex;i++)
		s[i]=temp[i];
}

void mergesort(int *s,int *temp,int startIndex,int endIndex){
    int mid=(startIndex+endIndex)/2;
	if(startIndex<endIndex){
	    mergesort(s,temp,startIndex,mid);
		mergesort(s,temp,mid+1,endIndex);
		merge(s,temp,startIndex,endIndex,mid);
	}
}

int main(){	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&s[i]);
	}
	mergesort(s,temp,0,n-1);
	printf("%d\n",sum);
	return 0;
}
