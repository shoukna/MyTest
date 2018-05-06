#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int maxn=100;
vector<int> twoSum(vector<int> nums,int target){
	map<int,int>map;
	vector<int>res;
	for(int i=0;i<(int)nums.size();i++){
	    map[nums[i]]=i;
	}
	for(int i=0;i<(int)nums.size();i++){
		auto p=map.find(target-nums[i]);
		if(p!=map.end()&&p->second!=i){
			res.push_back(i);
			res.push_back(p->second);
			break;
		}
	}
	return res;
}

int main()
{
	vector<int> arr;
	int c,target;
	vector<int> result;
	for(int i=0;i<3;i++){
		    cin>>c;
			arr.push_back(c);
		}
	
	scanf("%d",&target);
	result=twoSum(arr,target);
	cout<<result[0];
    cout<<result[1];

	return 0;
}

