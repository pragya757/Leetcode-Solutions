class Solution {
public:

    static bool cmp(string a, string b){

        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        // convert int → string
        for(int num : nums){
            arr.push_back(to_string(num));
        }

        // custom sort
        sort(arr.begin(), arr.end(), cmp);

        // edge case: all zeros
        if(arr[0] == "0"){
            return "0";
        }

        // join answer
        string ans = "";

        for(string s : arr){
            ans += s;
        }

        return ans;
    }
};
