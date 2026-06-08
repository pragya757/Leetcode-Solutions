class Solution {

public:

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();

        int n = mat[0].size();

        vector<int> ans;

        for(int d = 0; d < m + n - 1; d++) {


            vector<int> temp;



            int row, col;

            if(d < n) {

                row = 0;

                col = d;

            }

            else {

                row = d - n + 1;

                col = n - 1;

            }



            while(row < m && col >= 0) {

                temp.push_back(mat[row][col]);

                row++;

                col--;

            }



            if(d % 2 == 0) {

                reverse(temp.begin(), temp.end());

            }



            for(int x : temp) {

                ans.push_back(x);

            }

        }



        return ans;

    }

};
