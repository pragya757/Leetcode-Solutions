class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int,string>> people;
        int n=names.size();

        for(int i = 0; i < n; i++) {
            people.push_back({heights[i], names[i]});
        }

        sort(people.rbegin(), people.rend());

        vector<string> ans;

        for(auto p : people) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
