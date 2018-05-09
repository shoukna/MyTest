
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int m=0;
        for(int i=1;i<nums.size();i++){
            int j=i-1;
            if(nums[i]!=nums[j]){
                m=m+1;
               nums[m]=nums[i];
                
            }

           }
        
        return m+1;
    }
};
