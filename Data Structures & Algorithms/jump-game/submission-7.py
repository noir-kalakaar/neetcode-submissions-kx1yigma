class Solution:
    def canJump(self, nums: List[int]) -> bool:
        start = 0

        for i in range(len(nums)):
            if start<0:
                return False
            if(start<nums[i]):start=nums[i]
            start-=1
        return True