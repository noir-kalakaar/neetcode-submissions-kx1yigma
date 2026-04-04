class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(const auto& a:nums){
            int pos = lower_bound(dp.begin(),dp.end(),a)-dp.begin();
            if(pos == dp.size())dp.push_back(a);
            else dp[pos]=a;
        }
        return dp.size();
    }
};
