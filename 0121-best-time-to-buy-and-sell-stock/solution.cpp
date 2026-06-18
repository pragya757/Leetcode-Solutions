class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int minprice=1e9;
        for(int price:prices){
            minprice=min(minprice,price);
            int currentprofit=price-minprice;
            maxprofit=max(maxprofit,currentprofit);
        }
        return maxprofit;
    }
};
