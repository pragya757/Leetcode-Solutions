class Solution {
public:

    long long dp[20][11][2][2];
    int K;
    string num;

    long long solve(int pos,int prev,
                    bool tight,bool started){

        if(pos==num.size()){

            return started;
        }

        if(dp[pos][prev+1][tight][started]!=-1){

            return dp[pos][prev+1][tight][started];
        }

        int limit = tight ? num[pos]-'0' : 9;

        long long ans = 0;

        for(int d=0; d<=limit; d++){

            bool newTight =
                  tight && (d==limit);

            if(!started && d==0){

                ans += solve(pos+1,-1,
                             newTight,false);
            }

            else{

                if(prev==-1 ||
                   abs(d-prev)<=K){

                    ans += solve(pos+1,d,
                                 newTight,true);
                }
            }
        }

        return dp[pos][prev+1]
                 [tight][started]=ans;
    }

    long long countGood(long long x){

        if(x<0) return 0;

        num = to_string(x);

        memset(dp,-1,sizeof(dp));

        return solve(0,-1,1,0);
    }

    long long goodIntegers(long long l,
                           long long r,
                           int k) {

        auto denoluvira =
             make_tuple(l,r,k);

        K = k;

        return countGood(r)
               - countGood(l-1);
    }
};
