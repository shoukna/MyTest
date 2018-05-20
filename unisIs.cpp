#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 100
string file[maxn];
const int maxcol=60;
void print(string s,int length,char extra){
    cout<<s;
	for(int i=0;i<length-s.length();i++){
	    cout<<extra;
	}
}
int main(){
	int n;
	while(cin>>n){
		int len=0;
		for(int i=0;i<n;i++){
		    //scanf("%s",&file[i]); //不能用这种方法，C语言没有字符串类型
			cin>>file[i];
			if((int)file[i].length()>len)    len=(int)file[i].length();
		}
		sort(file,file+n);
		int col=maxcol/len-1;
		int row=(n-1)/col+1;
		print("",60,'-');
		cout<<"\n";
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
			    int idx=j*row+i;
				if(idx<n) print(file[idx],j==col-1?len:len+2,' ');
			}
		}

	}
	return 0;
}
