class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum buy price to a very large number (or the first price)
        int min_buy_price = 1e9; // Or simply prices[0] if the array is guaranteed non-empty
        // Initialize the maximum profit found so far to zero
        int max_profit = 0;

        // Iterate through each price in the given array
        for (int price : prices) {
            // Update the minimum buy price if the current price is lower
            min_buy_price = std::min(min_buy_price, price);
            
            // Calculate the potential profit if we sell at the current price
            int current_profit = price - min_buy_price;
            
            // Update the maximum profit if the current profit is higher
            max_profit = std::max(max_profit, current_profit);
        }

        // Return the maximum profit found across all potential transactions
        return max_profit;
    }
};

