class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<long long,int> len, freq;
        int ans = 1;

        for(int num : nums) {
            if(num == 1) {
                freq[1]++;
                continue;
            }

            long long root = sqrt(num);

            if(root * root == num && len.count(root) && freq[root] >= 2)
                len[num] = len[root] + 2;
            else
                len[num] = 1;

            ans = max(ans, len[num]);
            freq[num]++;
        }

        if(freq[1])
            ans = max(ans, (freq[1] % 2 ? freq[1] : freq[1] - 1));

        return ans;
    }
};
