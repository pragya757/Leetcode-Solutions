class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        data={}
        for i,x in enumerate(nums):
            if x not in data:
                data[x]= [i,i,None,1,True]
            else:
                first,prev,diff,count,valid=data[x]
                gap=i-prev
                if count==1:
                    diff=gap
                else:
                    if gap!=diff:
                        valid=False
                count+=1
                prev=i
                data[x]=[first,prev,diff,count,valid]
        ans=0
        for first,prev,diff,count,valid in data.values():
            if count>=3 and valid:
                ans+=1
        return ans
