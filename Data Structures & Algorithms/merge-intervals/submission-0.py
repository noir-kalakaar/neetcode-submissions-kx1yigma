class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        l = 0 

        intervals.sort()
        res = []
        while l<n-1:
            s,e = intervals[l]
            s1,e1 = intervals[l+1]

            if e<s1:
                res.append([s,e])
                l+=1
                continue
            else:
                s = min(s,s1)
                e = max(e,e1)
                intervals[l+1] = [s,e]
                l+=1
        res.append(intervals[n-1])
        return res        

