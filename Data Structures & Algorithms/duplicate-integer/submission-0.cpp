class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_multiset<int> num;
        bool ans = false;
        int n = nums.size();
        for(int i=0;i<n;i++){
            num.insert(nums[i]);
            if(num.count(nums[i])>1){
                ans = true;
                break;
            }
        }
        return ans;
    }
};