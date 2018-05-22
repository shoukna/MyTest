#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
using namespace std;
const int maxv=10000+10;
int n;
int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
bool read_list(int* a){
    string str;
	int x;
	n=0;
	if(!getline(cin,str)) return false;
	stringstream ss(str);
	while(ss>>x){
	    a[n++]=x;
	}
	return true;
}
int build(int L1,int R1,int L2,int R2){
	if(R1<L1) return 0;
	int root=post_order[R2];
	int p=L1;
	while(in_order[p]!=root) p++;
	lch[root]=build(L1,p-1,L2,L2+p-L1-1);
	rch[root]=build(p+1,R1,L2+p-L1,R2-1);
	return root;
}
int bestsum,bestv;
void def(int u,int sum){
    sum=sum+u;
	if(!lch[u]&&!rch[u]){
		if(sum<bestsum||(sum==bestsum&&u<bestv)){ bestsum=sum;bestv=u;}}
	if(lch[u]) def(lch[u],sum); 
	if(rch[u]) def(rch[u],sum);
}
int main(){
	while(read_list(in_order)){
	    read_list(post_order);
		build(0,n-1,0,n-1);
		bestsum=1000000000;
		def(post_order[n-1],0);
		printf("%d\n",bestv);
	}
	return 0; 
}
