class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int n=prices.size();
        int m=discounts.size();
        double total=0.0;

        for(int i=0;i<min(n,m);i++){
            total+=(double)prices[i]*(100-discounts[i])/100.0;
        }
        for(int i=min(n,m);i<n;i++){
            total+=prices[i];
        }
        return total;
    }
};
