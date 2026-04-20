class Solution:
    def rob(self, nums: List[int]) -> int:
        dpl = [0]*len(nums)
        dpr = [0]*len(nums)
        n = len(nums)
        if len(nums)==1:
            return nums[0]
        elif len(nums)==2:
            return max(nums[0],nums[1])

        dpl[0] = nums[0]
        dpl[1] = max(nums[1],nums[0])

        dpr[n-1]=nums[n-1]
        dpr[n-2]=max(nums[n-1],nums[n-2])

        for i in range(2,n-1):
            dpl[i]=max(dpl[i-1],dpl[i-2]+nums[i])
        for i in range(n-3,0,-1):
            dpr[i]=max(dpr[i+1],nums[i]+dpr[i+2])

        dpl[n-1] = dpl[n-2]
        dpr[0]=dpr[1]

        return max(dpl[n-1],dpr[0])