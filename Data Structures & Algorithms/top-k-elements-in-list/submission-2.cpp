class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(auto& num:nums){
            mp[num]++;
        }
        for(auto& m:mp){
            pq.push({m.second,m.first});
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            pair<int,int> top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        return res;
    }
};
