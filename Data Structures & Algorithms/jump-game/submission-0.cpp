class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),temp1=1;
        bool ans = true;
        for(int i=0;i<n-1;i++){
            if(nums[i]==0){
                while(nums[i-temp1]<=temp1){
                    temp1++;
                    if(i-temp1<0)return false;
                    }
            }
            temp1=1;
        }
        return true;
    }
};
