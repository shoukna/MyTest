#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;
vector<string>words;
map<string,int> cnt;
string repr(string s){
	string ans=s;
	for(int i=0;i<ans.length();i++){
		ans[i]=tolower(ans[i]);
	}
	sort(ans.begin(),ans.end());
	return ans;
}
int main(){
	string s;
	while(cin>>s){
		words.push_back(s);
		string r=repr(s);
		if(!cnt.count(r)) cnt[r]=0;
		cnt[r]++;
	}
	vector<string> ans;
	for(int i=0;i<words.size();i++){
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]); 
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
	    cout<<ans[i]<<"\n";
	}
	return 0;
}



