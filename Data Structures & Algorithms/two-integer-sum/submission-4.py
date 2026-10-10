class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        kv = {}
        for i in range(len(nums)):
            if target - nums[i] in kv:
                return [kv[target-nums[i]],i]
            kv[nums[i]]=i

            