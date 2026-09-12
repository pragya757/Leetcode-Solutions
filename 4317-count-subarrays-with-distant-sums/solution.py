class Solution:
    def distantSubarrays(self, nums: list[int], goal: int, k: int) -> int:
        n=len(nums)
        if k==0:
            return n*(n+1)//2
            
        prefix=[0]
        s=0
        for x in nums:
            s+=x
            prefix.append(s)
            
        values=sorted(set(prefix))
        m=len(values)
        
        bit=[0]*(m+1)
        
        def update(pos):
            pos+=1
            while pos<len(bit):
                bit[pos]+=1
                pos+=pos & -pos
        def query(pos):
            if pos<0:
                return 0
                
            pos+=1
            result=0
            while pos>0:
                result+=bit[pos]
                pos -= pos & -pos
            return result
            
        import bisect
        answer=0
        seen=0
        update(bisect.bisect_left(values,0))
        seen=1
        for current in prefix[1:]:
            limit1=current - goal+k
            pos1=bisect.bisect_left(values,limit1)
            smaller=query(pos1-1)
            answer+=seen-smaller

            limit2=current-goal-k
            pos2=bisect.bisect_right(values,limit2)-1
            answer+=query(pos2)
            pos=bisect.bisect_left(values,current)
            update(pos)

            seen+=1

        return answer
