class Solution {
public:

    int MOD = 1337;

    int power(int a, int b){

        int result = 1;
        a = a % MOD;

        for(int i=0; i<b; i++){

            result = (result * a) % MOD;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {

        int ans = 1;

        for(int digit : b){

            ans = ( power(ans,10) * power(a,digit) ) % MOD;
        }

        return ans;
    }
};
