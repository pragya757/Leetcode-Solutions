class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int>temp;
        for (int i=0; i<n; i++){
            int curr=nums[i];
            int exp=target-curr;

            if (temp.find(exp) != temp.end()){
                return {i, temp[exp]};
            }
            temp[curr]=i;
        }
        return{};
        
    }
};
