class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for(string word : words) {

            string lower = "";

            for(char ch : word) {
                lower += tolower(ch);
            }

            string row;

            if(row1.find(lower[0]) != string::npos)
                row = row1;
            else if(row2.find(lower[0]) != string::npos)
                row = row2;
            else
                row = row3;

            bool valid = true;

            for(char ch : lower) {

                if(row.find(ch) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                ans.push_back(word);
        }

        return ans;
    }
};
