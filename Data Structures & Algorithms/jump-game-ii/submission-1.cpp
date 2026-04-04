class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans=0,farthest=0,end=0;
        for(int i=0;i<n-1;i++){
            
            farthest = max(farthest,i+nums[i]);
            if(i==end){ans++;end=farthest;}

        }
        return ans;
    }
};
