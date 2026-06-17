class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,vector<string>& list2) {

        unordered_map<string,int> mp;
        int n=list1.size();
        for(int i=0;i<n;i++){

            mp[list1[i]] = i;
        }

        vector<string> ans;
        int mini = INT_MAX;
        int m=list2.size();
        for(int j=0;j<m;j++){

            if(mp.find(list2[j]) != mp.end()){

                int sum = j + mp[list2[j]];

                if(sum < mini){

                    mini = sum;

                    ans.clear();

                    ans.push_back(list2[j]);
                }

                else if(sum == mini){

                    ans.push_back(list2[j]);
                }
            }
        }

        return ans;
    }
};
