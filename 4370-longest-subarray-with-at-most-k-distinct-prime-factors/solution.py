class Solution:
    def longestSubarray(self, nums: list[int], k: int) -> int:
        MAX=max(nums)
        spf=list(range(MAX+1))
        for i in range(2,int(MAX**0.5)+1):
            if spf[i]==i:
                for j in range(i*i,MAX+1,i):
                    if spf[j]==j:
                        spf[j]=i
        factors=[]
        for x in nums:
            cur=set()
            while x>1:
                p=spf[x]
                cur.add(p)
                while x%p==0:
                    x//=p
            factors.append(cur)
        count={}
        distinct=0
        left=0
        ans=0

        for right in range(len(nums)):
            for p in factors[right]:
                if count.get(p,0)==0:
                    distinct+=1
                count[p]=count.get(p,0)+1
            while distinct>k:
                for p in factors[left]:
                    count[p]-=1
                    if count[p]==0:
                        distinct-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans
