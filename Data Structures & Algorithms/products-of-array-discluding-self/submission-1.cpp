class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        bool multi_zero=false,single_zero=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && single_zero)multi_zero=true;
            if(nums[i]==0)single_zero=true;
            if(nums[i]!=0)prod*=nums[i];
        }
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            if(multi_zero)res[i]=0;
            else if(single_zero && nums[i]!=0)res[i]=0;
            else if(single_zero && nums[i]==0)res[i]=prod;
            else if(!single_zero)res[i]=prod/nums[i];
        }
        return res;
    }
};
