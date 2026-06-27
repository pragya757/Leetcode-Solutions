class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //frequency count
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        //{frequency,number} make pair
        vector<pair<int,int>>arr;
        for(auto it:mp){
            arr.push_back({it.second,it.first});
        }
        //sort it in decending
        sort(arr.rbegin(),arr.rend());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
