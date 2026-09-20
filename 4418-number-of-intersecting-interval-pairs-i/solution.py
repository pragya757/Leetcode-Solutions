class Solution:
    def countIntersectingIntervals(self, intervals: list[list[int]]) -> int:
        starts=sorted(start for start,end in intervals)
        ends=sorted(end for start, end in intervals)

        n=len(intervals)
        j=0
        ans=0

        for i in range(n):
            while j<n and ends[j]<starts[i]:
                j+=1
            ans+=i-j
        return ans
