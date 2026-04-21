class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        l = 1

        intervals.sort()
        res = 0
        prevE = intervals[0][1]
        for s,e in intervals[1:]:
            if s>=prevE: 
                prevE = e
            else:
                res+=1
                prevE= min(e,prevE)
        return res

        

