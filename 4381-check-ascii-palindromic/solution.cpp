class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.size();
        for(int i=0;i<8*n/2;i++){
            int leftChar=i/8;
            int leftBit=7-(i%8);
            int j=8*n-1-i;
            int rightChar=j/8;
            int rightBit=7-(j%8);
            int a=((unsigned char)s[leftChar]>>leftBit)&1;
            int b=((unsigned char)s[rightChar]>>rightBit)&1;
            if(a!=b)
                return false;
        }
        return true;
    }
};
