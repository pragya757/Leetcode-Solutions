/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> nums;

        // linked list → array
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> ans(n,0);

        stack<int> st;   // store indexes

        for(int i=0; i<n; i++){

            while(!st.empty() && nums[i] > nums[st.top()]){

                int idx = st.top();
                st.pop();

                ans[idx] = nums[i];
            }

            st.push(i);
        }

        return ans;
    }
};
