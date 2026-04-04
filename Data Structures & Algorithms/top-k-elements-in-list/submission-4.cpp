class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto& num:nums){
            mp[num]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(auto& num:mp){
            freq[num.second].push_back(num.first);
        }
        vector<int> res;
        for(int i=nums.size();i>=1;i--){
            for(auto& gg:freq[i]){
                res.push_back(gg);
                if(res.size()==k)return res;
            }
        }
    }
};
