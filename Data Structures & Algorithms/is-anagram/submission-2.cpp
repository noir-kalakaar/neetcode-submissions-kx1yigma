class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        int n = s.size();
        int m = t.size();
        if(n!=m)return false;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            mp[t[i]]--;
        }
        for(auto& val:mp){
            if(val.second!=0)return false;
        }
        return true;

    }
};
