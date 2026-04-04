class Solution {
public:
    string longestPalindrome(string s) {
        int resInd = 0,resLen=0;
        

        int n = s.length();

        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>resLen){resLen = r-l+1;resInd=l;}
                r++;
                l--;
            }
            l=i;r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>resLen){resLen = r-l+1;resInd=l;}
                r++;
                l--;
            }
        }

        return s.substr(resInd,resLen);
    }
};
