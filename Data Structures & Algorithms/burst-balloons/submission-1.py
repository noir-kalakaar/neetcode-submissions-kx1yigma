class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        if len(nums) > 1 and len(set(nums)) == 1:
            return (nums[0]**3) * (len(nums)-2) + nums[0]**2 + nums[0]
        nums = [1]+nums+[1]
        dp = {}
        def dfs(l,r):
            if l>r:
                return 0
            if (l,r) in dp:
                return dp[(l,r)]
            dp[(l,r)]=0
            for i in range(l,r+1):
                coins = nums[i]*nums[l-1]*nums[r+1]
                coins+= dfs(l,i-1)+dfs(i+1,r)
                dp[(l,r)]=max(dp[(l,r)],coins)
            return dp[(l,r)]
        return dfs(1,len(nums)-2)