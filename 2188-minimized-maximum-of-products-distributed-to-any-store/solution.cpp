class Solution {
public:

    bool canDistribute(vector<int>& quantities,int n,int x) {
        int stores = 0;
        for(int q : quantities) {
            stores += (q + x - 1) / x;   // ceil(q/x)

            if(stores > n)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int st = 1;
        int end = *max_element(
                        quantities.begin(),
                        quantities.end());

        int ans = end;

        while(st <= end) {

            int mid = st + (end - st)/2;

            if(canDistribute(quantities,
                             n,
                             mid)) {

                ans = mid;        // possible answer
                end = mid - 1;   // try smaller
            }

            else {

                st = mid + 1;    // need bigger x
            }
        }

        return ans;
    }
};
