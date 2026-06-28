class Solution {
public:
    string capitalizeTitle(string title) {
        
        string word = "";
        string ans = "";

        for(int i=0; i<=title.size(); i++){

            // word completed
            if(i == title.size() || title[i]==' '){

                int n = word.size();

                if(n <= 2){

                    // all lowercase
                    for(int j=0; j<n; j++){
                        word[j] = tolower(word[j]);
                    }
                }
                else{

                    // first uppercase
                    word[0] = toupper(word[0]);

                    // rest lowercase
                    for(int j=1; j<n; j++){
                        word[j] = tolower(word[j]);
                    }
                }

                ans += word;

                if(i != title.size()){
                    ans += " ";
                }

                word = "";
            }

            else{
                word += title[i];
            }
        }

        return ans;
    }
};
