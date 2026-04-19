class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        stack = []
        n = len(heights)

        for i in range(n):
            start = i
            while stack and stack[-1][0]>heights[i]:
                height,ind = stack.pop()
                ans = max(ans,height*(i-ind))
                start = ind
            stack.append([heights[i],start])
        
        while stack:
            height,ind = stack.pop()
            ans = max(ans,height*(n-ind))
        return ans