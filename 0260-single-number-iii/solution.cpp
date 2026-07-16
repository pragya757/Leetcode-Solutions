class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        unsigned int diff = static_cast<unsigned int>(ans);
        diff = diff & (-diff);

        int a = 0, b = 0;

        for (int num : nums) {
            if (static_cast<unsigned int>(num) & diff)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};
