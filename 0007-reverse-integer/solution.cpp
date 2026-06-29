class Solution {
public:
    int reverse(int x) {

        long r = 0;     // use long for overflow check

        while(x){

            int digit = x % 10;     // take last digit

            r = r * 10 + digit;     // build reverse

            x = x / 10;             // remove last digit
        }

        if(r > INT_MAX || r < INT_MIN){
            return 0;
        }

        return (int)r;
    }
};
