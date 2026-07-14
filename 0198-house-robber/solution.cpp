class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int take=nums[i]+helper(nums,i+2);
        int leave=helper(nums,i+1);

        return dp[i]= max(take,leave);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return helper(nums,0);
    }
};
