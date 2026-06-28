class Solution {
public:

    bool isVowel(char ch){

        ch = tolower(ch);

        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    string reverseVowels(string s) {
        
        int left = 0;
        int right = s.size()-1;

        while(left < right){

            // move left until vowel
            while(left < right && !isVowel(s[left])){
                left++;
            }

            // move right until vowel
            while(left < right && !isVowel(s[right])){
                right--;
            }

            // swap vowels
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};
