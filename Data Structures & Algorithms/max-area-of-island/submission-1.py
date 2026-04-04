class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        dir=[[1,0],[0,1],[-1,0],[0,-1]]

        row=len(grid)
        col=len(grid[0])
        maxAns=0
        
        def dfs(r,c):
            if(r<0 or r>=row or c<0 or c>=col or grid[r][c]==0):
                return 0

            grid[r][c]=0
            ans=1
            for dr,dc in dir:
                ans=ans+dfs(r+dr,c+dc)
            return ans

        for r in range(row):
            for c in range(col):
                if grid[r][c]==1:
                    maxAns = max(maxAns,dfs(r,c))

        return maxAns

