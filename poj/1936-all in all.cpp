#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string s,t;
	int i,j;
	while(cin>>s>>t){
		i=j=0;
		while(1){
		if(s[i]==t[j]){
		    i++;j++;
		}
		else j++;
		if(i==s.length()){
		    cout<<"Yes"<<endl;break;
		}
		if(i<s.length()&&j==t.length()) {
		    cout<<"No"<<endl;break;
		}
		}
	}
}