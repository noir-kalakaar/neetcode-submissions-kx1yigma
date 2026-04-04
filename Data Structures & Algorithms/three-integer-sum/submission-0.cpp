class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int k;
        set<vector<int>> ss;
        for(int i=0;i<n;i++){
            k = 0-nums[i];
            unordered_map<int,int> tmp;
            for(int j=i+1;j<n;j++){
                vector<int> g;
                if(tmp.count(k-nums[j])){
                    g.push_back(-k);
                    g.push_back(k-nums[j]);
                    g.push_back(nums[j]);
                }
                tmp[nums[j]]++;
                if(!g.empty())ss.insert(g);
            }
        }
        for(auto it:ss){
            res.push_back(it);
        }
        return res;
    }
};


