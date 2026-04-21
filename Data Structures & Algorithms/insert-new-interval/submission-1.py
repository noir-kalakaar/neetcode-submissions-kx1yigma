class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start,end = newInterval
        index = 0
        res = []
        for i, (s,e) in enumerate(intervals):
            if end<s:
                res.append([start,end])
                return res+intervals[i:]
            elif start>e:
                res.append(intervals[i])
            else:
                start = min(start,s)
                end = max(end,e)
        res.append([start,end])
        return res
            
        
