class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        kv = {}
        freq = [[] for i in range(len(nums)+1)]

        for num in nums:
            kv[num]=1+kv.get(num,0)
        for ke,v in kv.items():
            freq[v].append(ke)
        res=[]
        for i in range(len(freq)-1,0,-1):
            for num in freq[i]:
                if len(res)>=k:
                    return res
                res.append(num)
        return res