class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        kv = {}
        for num in nums:
            if num in kv:
                return True
            kv[num]=1
        return False