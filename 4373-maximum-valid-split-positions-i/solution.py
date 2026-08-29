class Solution:
    def maxValidSplits(self, nums: list[int]) -> int:
        n=len(nums)
        pref=[0]*n
        pref[0]=nums[0]
        for i in range(1,n):
            pref[i]=gcd(pref[i-1],nums[i])
        suff=[0]*n
        suff[n-1]=nums[n-1]
        for i in range(n-2,-1,-1):
            suff[i]=gcd(nums[i],suff[i+1])
        ans=0
        for i in range(n-1):
            if pref[i]==suff[i+1]:
                ans+=1
        for remove in range(n):
            arr=nums[:remove]+nums[remove+1:]
            m=len(arr)
            p=[0]*m
            p[0]=arr[0]
            for i in range(1,m):
                p[i]=gcd(p[i-1],arr[i])
            s=[0]*m
            s[m-1]=arr[m-1]
            for i in range(m-2,-1,-1):
                s[i]=gcd(arr[i],s[i+1])
            score=0
            for i in range(m-1):
                if p[i]==s[i+1]:
                    score+=1
            ans=max(ans,score)
        return ans
