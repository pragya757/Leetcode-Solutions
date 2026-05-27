class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy_price=1e9;
        int max_profit=0;
        for (int price:prices){
            min_buy_price=min(min_buy_price,price);
            int current_profit=(price-min_buy_price);
            max_profit=max(max_profit,current_profit);
            
        }
        return max_profit;
        
    }
};
