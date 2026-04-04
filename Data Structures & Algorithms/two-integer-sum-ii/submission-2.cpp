class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        while(l<r){
            int temp = nums[l]+nums[r];
            if(temp<target)l++;
            else if(temp>target)r--;
            else return{l+1,r+1};
        }
        return {};
    }
};
