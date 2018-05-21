#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
struct Matrix{
    int a,b;
	Matrix(int a=0,int b=0):a(a),b(b){};
}m[26];
stack<Matrix> s;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    char name;
		cin>>name;
		int k=name-'A';
		cin>>m[k].a>>m[k].b;
	}
	 string expr;
	
	 while(cin>>expr){
		 int len=expr.length();
		 int ans=0;
		 int error=1;
		 for(int i=0;i<len;i++){
			 if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
			 else if(expr[i]==')'){
			     Matrix m2=s.top();s.pop();
				 Matrix m1=s.top();s.pop();
				 if(m1.b==m2.a) {ans=ans+m1.a*m1.b*m2.b;error=1;s.push(Matrix(m1.a,m2.b));}
				 else if(m1.b!=m2.a) {error=0;break;}
			 }
		 }
		 if(error) printf("%d\n",ans);
		 else printf("error");
		}
	
	return 0;
}
