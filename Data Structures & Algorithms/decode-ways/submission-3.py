class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [1]*(len(s)+1)
        n = len(s)
        
        
        for i in range(n-1,-1,-1):
            if s[i]=="0":
                dp[i]=0
            else:
                dp[i]=dp[i+1]
            
            if (i<n-1) and ((s[i]=="1") or (s[i]=="2" and ord(s[i+1])<=ord("6") and ord(s[i])>=ord("0"))):
                dp[i]+=dp[i+2]
            
        return dp[0]
            
                