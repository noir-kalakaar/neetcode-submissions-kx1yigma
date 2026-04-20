class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        pfx = 0
        sfx = 0
        res = nums[0]

        for i in range(n):
            pfx = nums[i]*(pfx or 1)
            sfx = nums[n-1-i]*(sfx or 1)
            res = max(res,max(pfx,sfx))
        return res
