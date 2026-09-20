class Solution:
    def largestPower(self, nums: list[int]) -> list[int]:
        n=len(nums)
        MAX=1<<15
        cnt=[0]*MAX
        for x in nums:
            cnt[x]+=1
        ans=[n]*15
        active=MAX-1
        pos=0

        while pos<n and active:
            full=[]
            full_count=0
            best=-1
            best_val=-1

            for x in range(MAX):
                if cnt[x]==0:
                    continue
                v=x&active
                if v ==active:
                    full.append(x)
                    full_count+=cnt[x]
                elif v>best_val:
                    best_val=v
                    best=x
            if full_count:
                for x in full:
                    cnt[x]=0
                pos+=full_count
                if pos==n:
                    break
                continue
            x=best
            for b in range(14,-1,-1):
                if(active&(1<<b)) and not (x&(1<<b)):
                    ans[14-b]=pos
            active &=x
            cnt[x]-=1
            pos+=1
        return ans
