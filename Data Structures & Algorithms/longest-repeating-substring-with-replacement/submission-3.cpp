class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int ans=0;
        if(n<=1)return n;
        for(int i=0;i<26;i++){
            int l=0,r=0;
            char tmp='A'+i;
            // int tmpans=0;
            int g=k;
            while(r<n){ 
                if(s[r]==tmp){
                    r++;
                }
                else if(s[r]!=tmp && g>0){

                    r++;
                    g--;
                }
                else if(g==0){
                    if(s[l]!=tmp)g++;
                    l++;
                }
                ans=max(ans,r-l);
            }
        }
        return ans;
    }
};
