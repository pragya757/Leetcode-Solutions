class Solution {
public:

    vector<int> dp;

    int helper(vector<int>& coins, int amount){

        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return INT_MAX;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini = INT_MAX;

        for(int coin : coins){

            int ans = helper(coins, amount - coin);

            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.resize(amount + 1, -1);

        int ans = helper(coins, amount);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};
