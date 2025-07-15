class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        left = 0
        total = 0
        result = 0

        for right in range(len(nums)):
            total += nums[right]

            # While the total required to make all elements equal to nums[right] exceeds k
            while nums[right] * (right - left + 1) - total > k:
                total -= nums[left]
                left += 1

            result = max(result, right - left + 1)

        return result

