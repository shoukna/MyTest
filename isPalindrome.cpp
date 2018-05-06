#include<cstdio>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int x;
	cin>>x;
	if(x<0) cout<<"false1";
	int m,n=1;
	int a[100];
	int y=x;
	int num=0;
	for(int i=0;n!=0;i++){
		m=y%10;
		n=y/10;
                y=n;
		a[i]=m;
		num++;
		cout<<"a[i]:"<<a[i]<<"\n";
	}
	int b=0;
	for(int i=num;i>0;i--){
		b=b+a[i-1]*pow(10,num-i);
	}
	cout<<b;
        if(b==x)
		cout<<"true";
        else cout<<"false"; 
	return 0;
}


