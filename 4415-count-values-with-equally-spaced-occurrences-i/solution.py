class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        pos={}
        for i, x in enumerate(nums):
            if x not in pos:
                pos[x]=[]
            pos[x].append(i)
        ans=0
        for x in pos:
            if len(pos[x])==3:
                a,b,c=pos[x]
                if b-a==c-b:
                    ans+=1
        return ans
