class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string g="";
        for(int i=0;i<n;i++){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0'&&s[i]<='9'))g+=tolower(s[i]);
        }
        n = g.length()-1;
        int i=0;
        while(i<n){
            if(g[i]!=g[n])return false;
            i++;n--;
        }
        return true;
    }
};
