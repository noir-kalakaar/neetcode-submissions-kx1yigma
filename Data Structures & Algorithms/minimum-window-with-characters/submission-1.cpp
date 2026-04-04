class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(),m=t.size();
        if(m==0 || m>n)return "";
        unordered_map<char,int> mp,window;
        for(auto& c:t)mp[c]++;
        int l=0;
        int need = mp.size(),have=0;
        pair<int,int> res={-1,-1};

        int reslen=n+1;
        for(int r=0;r<n;r++){
            char c = s[r];
            window[c]++;
            if(mp.count(c) && window[c]==mp[c])have++;
            while(have==need){
                if(r-l+1<reslen){
                    reslen = min(r-l+1,reslen);
                    res = {l,r};
                }
                window[s[l]]--;
                if(mp.count(s[l]) && window[s[l]]<mp[s[l]])have--;
                l++;
            }
        }
        if(reslen == n+1)return "";
        else return s.substr(res.first,reslen);
    }
};
