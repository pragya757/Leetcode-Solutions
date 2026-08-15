class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;
        for(int k=0;k<n;k++){
            int cost=k;
            for(int i=0;i<n/2;i++){
                char a=s[(i+k)%n];
                char b=s[(n-1-i+k)%n];
                int d1=(a-b+26)%26;
                int d2=(b-a+26)%26;
                cost+=min(d1,d2);
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};
