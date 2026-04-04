class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> ch,ch1;
        int n = s.size(),m=t.size();
        bool ans= true;
        if(n!=m){ans = false;return ans;}
        for(int i=0;i<n;i++){
            ch.insert(s[i]);
            ch1.insert(t[i]);
        }
        for(int i=0;i<m;i++){
            if(ch1.count(t[i])!=ch.count(t[i]))ans = false;
        }
        return ans;
    }
};
