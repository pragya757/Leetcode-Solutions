class Solution {
public:

    vector<int> dp;

    int helper(vector<int>& nums, int i, int end){

        if(i > end){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int take = nums[i] + helper(nums, i+2, end);
        int leave = helper(nums, i+1, end);

        return dp[i] = max(take, leave);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        // Case 1 : Exclude last house
        dp.assign(n, -1);
        int case1 = helper(nums, 0, n-2);

        // Case 2 : Exclude first house
        dp.assign(n, -1);
        int case2 = helper(nums, 1, n-1);

        return max(case1, case2);
    }
};
