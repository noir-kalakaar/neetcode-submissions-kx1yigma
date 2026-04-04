class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++){
             ans+=strs[i]+",&44,";  
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if (s.empty()) return ans;

        int tmp=0;
        for(int i=0;i<s.length()-4;i++){
            if(s[i]==',' && s[i+1]=='&' && s[i+2]=='4' && s[i+3]=='4' && s[i+4]==','){
                ans.push_back(s.substr(tmp,i-tmp));
                tmp=i+5;
            }
        }
        return ans;
    }
};
