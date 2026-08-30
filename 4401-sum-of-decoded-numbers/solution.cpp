class Solution {
public:
    const long long MOD=1000000007;
    long long power(long long x,long long y) {
        long long result=1;
        while(y>0){
            if(y&1)
                result=(result*x)%MOD;
            x=(x*x)%MOD;
            y/=2;
        }
        return result;
    }
    
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;
        for(long long n:nums){
            int width=n%10;
            long long d=n/10;
            string s=to_string(d);
            long long x=stoll(s.substr(0,width));
            long long y=stoll(s.substr(width));
            ans=(ans+power(x,y))%MOD;
        }
        return (int)ans;
    }
};
