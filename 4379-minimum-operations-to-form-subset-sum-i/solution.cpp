class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF=1e9;
        vector<int> dp(sum+1,INF);
        dp[0]=0;
        for(int x:nums) {
            vector<pair<int,int>> options;
            long long v=x;
            int cost=0;
            while(v<=sum) {
                options.push_back({(int)v,cost});
                v*=2;
                cost++;
            }
            v=x;
            cost=0;
            while(v>0)  {
                v/=2;
                cost++;
                if(v>0 && v<=sum) {
                    options.push_back({(int)v,cost});
                }
            }
            sort(options.begin(),options.end());
            vector<pair<int,int>> best;
            for(auto p:options) {
                if(best.empty() || best.back().first != p.first) {
                    best.push_back(p);
                } else {
                    best.back().second=min(best.back().second, p.second);
                }
            }
            vector<int> ndp=dp;
            for(int s=0;s<=sum;s++) {
                if(dp[s]==INF)
                    continue;
                for(auto p:best) {
                    int value=p.first;
                    int operations=p.second;
                    if(s+value<=sum) {
                        ndp[s+value]=min(ndp[s+value],dp[s]+operations);
                    }
                }
            }
            dp=ndp;
        }
        return dp[sum]== INF? -1:dp[sum];
    }
};
