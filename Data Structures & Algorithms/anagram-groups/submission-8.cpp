class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            vector<int> s(26,0);
            for(auto& c:strs[i])s[c-'a']++;
            string g="#";
            for(auto& gg:s){
                g+=to_string(gg);
                g+="#";
            }
            mp[g].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto& rr:mp){
            res.push_back(rr.second);
        }
        return res;

    }
};
