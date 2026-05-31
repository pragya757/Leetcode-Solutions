class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int i=0;
        int n=strs.size();
        for (i=0;i<n;i++){
            while(strs[i].find(prefix)!=0){
                prefix.pop_back();
            }

        }
        return prefix;
    }
};
