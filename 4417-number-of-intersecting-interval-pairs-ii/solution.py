class Solution:
    def countIntersectingIntervals(self, intervals: list[list[int]]) -> int:
        starts=sorted(x[0] for x in intervals)
        end=sorted(x[1] for x in intervals)

        ans=0
        j=0
        n=len(intervals)

        for i in range(n):
            while j<n and end[j]<starts[i]:
                j+=1
            ans+=i-j
        return ans
