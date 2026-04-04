class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int a = nums[0];
        int k=0;
        for(int b=n;b>=1;b/=2){
            while(k+b<n && nums[k+b]>a)k+=b;
        }
        if(k==n-1)return nums[0];
        return nums[k+1];
    }
};
