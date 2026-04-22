class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        sum1 = n*(n+1)
        sum1//=2

        for i in range(n):
            sum1-=nums[i]
        
        return sum1
