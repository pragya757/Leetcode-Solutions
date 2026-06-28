class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        // count frequency
        for(char ch : s){

            freq[ch]++;
        }

        vector<pair<char,int>> arr;

        // store character and frequency
        for(auto it : freq){

            arr.push_back(it);
        }

        // sort in decreasing frequency
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){

            return a.second > b.second;
        });

        string ans = "";

        // build answer
        for(auto it : arr){

            ans += string(it.second, it.first);
        }

        return ans;
    }
};
