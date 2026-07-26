class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;

        int i=0;
        int j=0;
        int n=series1.size();
        int m=series2.size();

        while(i<n || j<m){
            int t;
            if(j==m || (i<n && series1[i][0] < series2[j][0])){
                t=series1[i][0];
            }
            else if(i==n || series2[j][0]<series1[i][0]){
                t=series2[j][0];
            }
            else{
                t=series1[i][0];
            }
            int y1=(i<n) ? series1[i][1]:0;
            int y2=(j<m) ? series2[j][1]:0;

            ans.push_back({t,y1+y2});

            if(i<n && series1[i][0]==t){
                i++;
            }
            if(j<m && series2[j][0]==t){
                j++;
            }
        }
        return ans;
    }
};
