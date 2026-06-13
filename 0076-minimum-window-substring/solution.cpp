class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);

        for(char ch : t){
            freq[ch]++;
        }

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            // if useful char
            if(freq[s[right]] > 0){
                count++;
            }

            freq[s[right]]--;

            // valid window found
            while(count == t.size()) {

                // update answer
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                // remove left char
                freq[s[left]]++;

                if(freq[s[left]] > 0){
                    count--;
                }

                left++;
            }
        }

        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(start, minLen);
    }
};
