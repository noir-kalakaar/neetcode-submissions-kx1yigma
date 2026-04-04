class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax=nums[0],currMin=nums[0];
        int res = nums[0];
        
        for(int i=1;i<n;i++){
            int temp = currMax*nums[i];
            currMax = max(max(currMax*nums[i],currMin*nums[i]),nums[i]);
            currMin = min(min(currMin*nums[i],temp),nums[i]);
            res = max(res,currMax);
        }
        return res;
    }
};
