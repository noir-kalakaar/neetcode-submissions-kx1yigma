class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1,tmp=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1)tmp++;
            else if(nums[i]-nums[i-1]>1)tmp=1;  
            ans=max(ans,tmp);
        }
        if(nums.size()==0)return 0;
        return ans;
    }
};
