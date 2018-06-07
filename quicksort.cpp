#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
int a[maxn];
void quicksort(int *a,int l,int r){
	if(l<r){
	    int x=a[l];
		int i=l,j=r;
		while(i<j&&a[j]>x) j--;
		if(i<j) a[i++]=a[j];
		while(i<j&&a[i]<x) i++;
		if(i<j) a[j--]=a[i];
		a[i]=x;
		quicksort(a,l,i-1);
		quicksort(a,i+1,r);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
