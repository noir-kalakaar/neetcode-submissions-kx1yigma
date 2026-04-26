from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        #tails
        #make a "fake" increasing subsequence which keeps increeasing and if we find something small, we replace it
        n = len(nums)
        tails=[]
        ans=0
        for i in range(n):
            ind = bisect_left(tails,nums[i])
            if ind == len(tails):
                tails.append(nums[i])
            else:
                tails[ind]=nums[i]
        return len(tails)