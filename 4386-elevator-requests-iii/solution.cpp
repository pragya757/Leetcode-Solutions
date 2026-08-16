class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int k=requests.size();
        int total=1<<k;
        vector<vector<long long>>dp(total,vector<long long>(k,LLONG_MAX));
        for(int i=0;i<k;i++){
            long long travel=abs(start-requests[i][1]);
            long long time=max(travel,(long long) requests[i][0]);
            dp[1<<i][i]=time;
        }
        for(int mask=1;mask<total;mask++){
            for(int last=0;last<k;last++){
                if(dp[mask][last]==LLONG_MAX)
                    continue;
                long long curTime=dp[mask][last];
                int curFloor=requests[last][1];
                for(int next=0;next<k;next++){
                    if(mask & (1<< next))
                        continue;
                    int nextFloor=requests[next][1];
                    long long travel=abs(curFloor-nextFloor);
                    long long arrivalTime=requests[next][0];
                    long long newTime=max(curTime+travel,arrivalTime);
                    int newMask=mask|(1<<next);
                    dp[newMask][next]=min(dp[newMask][next],newTime);
                }
            }
        }
        long long ans=LLONG_MAX;
        int full=total-1;
        for(int last=0;last<k;last++){
            ans=min(ans,dp[full][last]);
        }
        return ans;
    }
};
