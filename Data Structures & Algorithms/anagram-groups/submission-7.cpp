class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(const auto& s:strs){
            vector<int> count(26);
            for(char c:s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1;i<26;i++){
                key+='$$'+to_string(count[i]);
            } 
            mp[key].push_back(s);
        }
        for(const auto& g:mp){
            ans.push_back(g.second);
        }
        return ans;
    }
};
