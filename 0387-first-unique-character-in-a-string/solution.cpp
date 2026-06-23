class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> freq(26,0);

        // count frequency
        for(char ch : s){

            freq[ch-'a']++;
        }

        // find first unique
        for(int i=0; i<s.length(); i++){

            if(freq[s[i]-'a'] == 1){

                return i;
            }
        }

        return -1;
    }
};
