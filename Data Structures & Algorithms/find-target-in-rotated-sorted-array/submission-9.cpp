class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = -1;
        int a = nums[0];
        for(int b=n;b>0;b/=2){
            while(k+b<n && nums[k+b]>=a)k+=b;
        }
        int pivot=(k+1)%n;
        // if(nums[pivot]==target)return 5;        
        k=-1;
        for(int b=n;b>0;b/=2){
            while(k+b<n && nums[(k+b+pivot)%n]<target)k+=b;
        }
        int ind = (k+1+pivot)%n;
        // if(ind==n)return -1;
        if(nums[ind]==target)return ind;
        return -1;   

        
    }
};
