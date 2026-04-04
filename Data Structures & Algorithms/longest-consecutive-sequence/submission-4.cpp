class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(),nums.end());
        int ans = 0;
        for(const auto& num:nums){
            if(numsSet.find(num-1)==numsSet.end()){
                int length = 1;
                while(numsSet.find(num+length)!=numsSet.end())length++;
                ans = max(ans,length);
            }
        }
        return ans;
    }
};
