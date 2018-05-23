#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<string>
using namespace std;
const int maxn=1000;
int sum[maxn];
void build(int p){
	int v;
	cin>>v;
	if(v==-1) return;
	sum[p]=sum[p]+v;
	build(p-1);build(p+1);
}
bool init(){
    int v;
	cin>>v;
	if(v==-1) return false;
	memset(sum,0,sizeof(sum));
	sum[maxn/2]=v;
	build(maxn/2-1);build(maxn/2+1);
	return true;
}
int main(){
	int kase=0;
	while(init()){
	    int i=0;
		while(sum[i]==0) i++;
		cout<<"Case "<<kase++<<":\n"<<sum[i++];
		while(sum[i]!=0) cout<<" "<<sum[i++];
		cout<<"\n";
	}
	return 0; 
}
