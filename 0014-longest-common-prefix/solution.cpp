class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string str=strs[0];
        for(int i=0;i<n;i++){
            while(strs[i].find(str)!=0){
                str.pop_back();
            }
        }
        return str;
    }
};
