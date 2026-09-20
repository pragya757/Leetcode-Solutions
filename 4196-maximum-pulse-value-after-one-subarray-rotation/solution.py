class Solution:
    def maxValue(self, nums: List[int]) -> int:
        n=len(nums)
        pref=[0]*(n+1)
        for i in range(n):
            if i%2==0:
                pref[i+1]=pref[i]+nums[i]
            else:
                pref[i+1]=pref[i]-nums[i]
        original=pref[n]
        ans=original
        mx=[float('-inf'),float('-inf')]
        for k in range(2,n+1):
            i=k-2
            mx[i%2]=max(mx[i%2],pref[i])
            
            ans=max(ans,original+2*(mx[k%2]-pref[k]))
        return ans
