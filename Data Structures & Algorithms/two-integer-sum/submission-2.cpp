class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<n;i++){
            
            if(m.find(target-nums[i])!=m.end()){
               
                
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                
                
                return ans;
            }
            m[nums[i]]=i;
        }
        
        
    }
};
