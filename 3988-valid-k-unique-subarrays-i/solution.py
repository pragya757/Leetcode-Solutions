class Solution:
    def validSubarrays(self, nums: list[int], k: int, queries: list[list[int]]) -> list[bool]:
        n=len(nums)
        q=len(queries)
        block=max(1,int(n/max(1,q)**0.5))
        qs=[]
        for i,(l,r) in enumerate(queries):
            qs.append((l,r,i))
        qs.sort(key=lambda x:(
            x[0]//block,
            x[1]if (x[0]//block)%2==0 else -x[1]
        ))
        freq=[0]*100001
        distinct=0
        odd=0

        cur_l=0
        cur_r=-1

        ans=[False]*q
        def add(x):
            nonlocal distinct,odd
            if freq[x]==0:
                distinct+=1
            if freq[x]%2==1:
                odd-=1
            freq[x]+=1
            if freq[x]%2==1:
                odd+=1
        def remove(x):
            nonlocal distinct,odd
            if freq[x]%2==1:
                odd-=1
            freq[x]-=1
            if freq[x]%2==1:
                odd+=1
            if freq[x]==0:
                distinct-=1
        for l , r, idx in qs:
            while cur_l>l:
                cur_l-=1
                add(nums[cur_l])
            while cur_r<r:
                cur_r+=1
                add(nums[cur_r])
            while cur_l<l:
                remove(nums[cur_l])
                cur_l+=1
            while cur_r>r:
                remove(nums[cur_r])
                cur_r-=1
            ans[idx]=(distinct==k and odd==0)
        return ans
