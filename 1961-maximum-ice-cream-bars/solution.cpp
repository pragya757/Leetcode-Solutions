class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        vector<int> freq(100001,0);

        // count frequency
        for(int i=0;i<costs.size();i++){

            freq[costs[i]]++;
        }

        int count = 0;

        // buy cheapest first
        for(int cost=1; cost<=100000; cost++){

            if(freq[cost] > 0){

                // maximum bars we can buy
                int canBuy = min(freq[cost],
                                 coins/cost);

                count += canBuy;

                coins -= canBuy*cost;

                if(coins < cost){

                    break;
                }
            }
        }

        return count;
    }
};
