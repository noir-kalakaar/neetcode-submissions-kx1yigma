class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans =0
        n = len(heights)
        stack = []
        for i in range(n):
            start = i
            while stack and stack[-1][1] > heights[i]:
                ind = stack[-1][0]
                height = stack[-1][1]
                stack.pop()
                ans = max(ans,height*(i-ind))
                start = ind
            stack.append((start,heights[i]))
        
        for i in range(len(stack)):
            h = stack[i][1]
            ind = stack[i][0]
            ans = max(ans,h*(n-ind))
        
        return ans