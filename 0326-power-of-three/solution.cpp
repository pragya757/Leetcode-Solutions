class Solution {
public:
    bool isPowerOfThree(int n) {
        for (int i=0; i<=30; i++){
            long long ans= (long long)pow(3,i);
            if (ans==n){
                return true;
            }
        }
        return false;
    }
};
