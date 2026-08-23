class Solution:
    def findDisappearedNumbers(self, nums: list[int], lower: int, upper: int) -> list[list[int]]:
        present=set(nums)
        ans=[]
        start=None
        for x in range(lower,upper+1):
            if x not in present:
                if start is None:
                    start=x
            else:
                if start is not None:
                    ans.append([start,x-1])
                    start=None
        if start is not None:
            ans.append([start,upper])
        return ans
        
