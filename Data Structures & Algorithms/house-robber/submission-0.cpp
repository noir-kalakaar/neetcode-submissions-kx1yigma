class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        dp[2]=max(dp[1],dp[0]+nums[2]);

        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp[n-1];

    }
};
