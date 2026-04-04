class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
    

        int l=0,r=0,best_l,res=INT_MAX;

        while(r<n && !mp[s[r]])r++;
        if(r==n)return "";
        l=r;
        if(mp[s[r]]>0){mp[s[r]]--;
        r++;
        m--;}
  
          while (r <= n) {
            if (m == 0) {
                if (r - l < res) {
                    res = r - l;
                    best_l = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) m++;
                l++;
            } else {
                if (r == n) break;
                if (mp[s[r]] > 0) m--;
                mp[s[r]]--;
                r++;
            }
        }

        return res==INT_MAX ? "" : s.substr(best_l,res);


    }
};
