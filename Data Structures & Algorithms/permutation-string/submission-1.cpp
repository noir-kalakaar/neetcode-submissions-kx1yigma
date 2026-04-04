class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),m=s2.size();
        if(n>m)return false;

        vector<int> a1(26,0),a2(26,0);
        for(int i=0;i<n;i++){
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(a1[i]==a2[i])cnt++;
        }        
        int l=0,r=n;
        // if(cnt==26)return true;
        while(r<m){
            if(cnt==26)return true;
            int rightInd = s2[r]-'a';
            
            a2[rightInd]++;

            if(a2[rightInd]==a1[rightInd])cnt++;
            else if(a1[rightInd]+1==a2[rightInd])cnt--;

            int leftInd = s2[l]-'a';
            a2[leftInd]--;
            if(a2[leftInd]==a1[leftInd])cnt++;
            else if(a2[leftInd]+1==a1[leftInd])cnt--;

            l++;r++;



        }
        return cnt==26;

    }
};
