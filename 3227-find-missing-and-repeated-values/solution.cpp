class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();

        unordered_set<int> s;

        int repeated = -1;
        int missing = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(s.find(grid[i][j]) != s.end()) {
                    repeated = grid[i][j];
                }

                s.insert(grid[i][j]);
            }
        }

        for(int num = 1; num <= n * n; num++) {

            if(s.find(num) == s.end()) {
                missing = num;
                break;
            }
        }

        return {repeated, missing};
    }
};
