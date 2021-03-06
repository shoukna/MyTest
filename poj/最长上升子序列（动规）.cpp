#include<cstdlib>
#include<cstdio>
#include<stack>
using namespace std;
const int maxn=100;
int a[maxn];
int d[maxn];
int id;
int pre[maxn];
void print(){
	int k=id;
	stack<int>s;
	while(k>0){
		s.push(a[k]);
		k=pre[k];
	}
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
}
int main(){
	int n;
	int maxnum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	d[1]=1;
	pre[1]=-1;
	for(int i=2;i<=n;i++){
		d[i]=1;
		for(int j=i-1;j>=1;j--){
			if((a[i]>a[j])&&(d[i]<d[j]+1)) {
			    d[i]=d[j]+1;
				pre[i]=j;
			}
		}
		if(d[i]>maxnum) {maxnum=d[i];id=i;}
	}
		printf("%d\n",maxnum);
		print();
		printf("\n");
}
