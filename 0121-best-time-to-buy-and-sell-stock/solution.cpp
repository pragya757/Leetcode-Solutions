class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=1e9;
        int maxprice=0;
        for(int price: prices){
            minprice=min(minprice, price);
            int currprice=price-minprice;
            maxprice=max(maxprice,currprice);
        }
        return maxprice;
    }
};
