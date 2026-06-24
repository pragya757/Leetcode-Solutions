class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(string token : tokens){

            // if operator
            if(token=="+" || token=="-" || token=="*" || token=="/"){

                int a = st.top();   // second operand
                st.pop();

                int b = st.top();   // first operand
                st.pop();

                if(token == "+"){
                    st.push(b+a);
                }
                else if(token == "-"){
                    st.push(b-a);
                }
                else if(token == "*"){
                    st.push(b*a);
                }
                else{
                    st.push(b/a);
                }
            }

            // if number
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
