class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while (right < nums.size()) {
            if (nums[right] == 0)
                zeroCount++;

            while (zeroCount > 1) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            // Length of current window minus 1 (since we need to delete one element)
            maxLength = max(maxLength, right - left);

            right++;
        }

        return maxLength;
    }
};

