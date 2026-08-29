class Solution:
    def largestString(self, nums: list[int]) -> list[str]:
        ans=[]
        for x in nums:
            s=[]
            z=x//(1<<25)
            if z:
                s.append('z'*z)
                x%=(1<<25)
            for k in range(24,-1,-1):
                if x>=(1<<k):
                    s.append(chr(ord('a')+k))
                    x-=(1<<k)
            ans.append(''.join(s))
        return ans
