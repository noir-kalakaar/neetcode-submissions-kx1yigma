class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pfxMax(n),sfxMax(n);
        pfxMax[0] = a[0];
        sfxMax[n-1] = a[n-1];
        for(int i=1;i<n;i++){
            if(i%k==0)pfxMax[i]=a[i];
            else pfxMax[i] = max(a[i],pfxMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            if((i%k)==0)sfxMax[i]=a[i];
            else sfxMax[i]=max(a[i],sfxMax[i+1]);
        }
        vector<int> res(n-k+1);
        
        for(int i=0;i<n-k+1;i++){
            res[i]=max(pfxMax[i+k-1],sfxMax[i]);
        }
        return res;

    }
};
