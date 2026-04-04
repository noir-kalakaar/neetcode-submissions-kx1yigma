class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char,int> mp;
        int l = 0,res = 0;
        if(s.size()<=1)return n;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=l){
                l = mp[s[i]]+1;
            }
            mp[s[i]]=i;
            res=max(res,i-l+1);
        }
        return res;

    }
};
