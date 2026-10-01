class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i=0; i<s.size(); i++){

            // opening bracket
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }

            // closing bracket
            else{

                // no opening bracket available
                if(st.empty()){
                    return false;
                }

                // check matching
                if( (s[i]==')' && st.top()!='(') ||
                    (s[i]=='}' && st.top()!='{') ||
                    (s[i]==']' && st.top()!='[') ){
                    
                    return false;
                }

                // matched → remove
                st.pop();
            }
        }

        return st.empty();
    }
};
