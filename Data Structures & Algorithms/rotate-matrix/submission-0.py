class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        r = n-1
        l=0

        while(l<r):
            for i in range(0,r-l):
                topLeft = matrix[l][l+i]
                matrix[l][l+i] = matrix[r-i][l]
                matrix[r-i][l]=matrix[r][r-i]
                matrix[r][r-i]=matrix[l+i][r]
                matrix[l+i][r]=topLeft
            r-=1
            l+=1
        