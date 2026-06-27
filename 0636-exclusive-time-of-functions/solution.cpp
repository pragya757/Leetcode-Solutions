class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> ans(n, 0);
        stack<int> st;
        
        int prevTime = 0;
        
        for(string log : logs){
            
            // split string
            int first = log.find(':');
            int second = log.find(':', first + 1);
            
            int id = stoi(log.substr(0, first));
            string type = log.substr(first + 1, second - first - 1);
            int time = stoi(log.substr(second + 1));
            
            
            if(type == "start"){
                
                // old function running till now
                if(!st.empty()){
                    ans[st.top()] += time - prevTime;
                }
                
                st.push(id);
                prevTime = time;
            }
            
            else{
                
                // function ends
                ans[st.top()] += time - prevTime + 1;
                
                st.pop();
                
                prevTime = time + 1;
            }
        }
        
        return ans;
    }
};
