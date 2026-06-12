class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        reverse(s.begin(),s.end()); //words reverse
        for(int i=0;i<n;i++){    // for particular charcter of words for reversing
            string word="";
            while(i<n && s[i]!= ' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(), word.end()); //reversing the charcter
            if(word.length() >0){
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};
