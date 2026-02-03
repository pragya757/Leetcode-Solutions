class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int count = 0, ans = 0;

        while (i < n) {

            if (isVowel(s[i])) {
                count++;
            }
            i++;

            
            if (i - j > k) {
                if (isVowel(s[j])) {
                    count--;
                }
                j++;
            }

            
            if (i - j == k) {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};

