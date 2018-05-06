#include<cstdio>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int x;
    scanf("%d",&x);
    if(x>(pow(2,31)-1)||x<(-pow(2,31))){
        cout<<"error111";
	return 0;
    }
    int a[100];
    int m,n=1;
    int i=0;
    int num;
    for(i=0,num=0;n!=0;i++){
	    m=x%10; //最右的数
            a[i]=m;
            n=x/10;
            x=n;
            num++;
            cout<<"a[i]"<<a[i];
    }
    int b=0;
    for(int i=num;i>0;i--){
	b=b+a[i-1]*pow(10,(num-i));
    }
    cout<<"b:"<<b<<"\n";
    if(b>(pow(2,31)-1)||b<=(-pow(2,31))){
	    cout<<"error222";
	    return 0;
    }
    return 0;
}

