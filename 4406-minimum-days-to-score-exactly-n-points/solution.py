class Solution:
    def minDays(self, n: int) -> int:
        dp=[10**9]*(n+1)
        dp[0]=-1
        for score in range(1,n+1):
            k=1
            while k*(k+1)//2<=score:
                points=k*(k+1)//2
                dp[score]=min(dp[score],dp[score-points]+k+1)
                k+=1
        return dp[n]
