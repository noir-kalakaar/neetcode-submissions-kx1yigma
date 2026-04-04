class TrieNode:
    def __init__(self):
        self.children={}
        self.EndofWord=False
    def addword(self,word):
        cur = self
        for c in word:
            if c not in cur.children:
                cur.children[c]=TrieNode()
            cur = cur.children[c]
        cur.EndofWord = True
class Solution:
    
    

    

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = set()
        visit = set()
        root = TrieNode()
        for word in words:
            root.addword(word)
        row = len(board)
        col = len(board[0])
        dir = [[0,1],[0,-1],[1,0],[-1,0]]

        def dfs(r,c,cur,word):
            if r<0 or c<0 or r>=row or c>=col or (r,c) in visit or board[r][c] not in cur.children:
                return
            visit.add((r,c))
            cur = cur.children[board[r][c]]
            word+=board[r][c]
            if cur.EndofWord:
                res.add(word)
            for dr,dc in dir:
                dfs(r+dr,c+dc,cur,word)
            visit.remove((r,c))
        
        for r in range(row):
            for c in range(col):
                dfs(r,c,root,"")
        
        return list(res)


        