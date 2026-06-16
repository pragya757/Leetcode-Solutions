class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // remove from beginning
        while(head && head->val == val){
            head = head->next;
        }

        ListNode* curr = head;

        // remove from middle/end
        while(curr && curr->next){

            if(curr->next->val == val){

                curr->next = curr->next->next;
            }
            else{

                curr = curr->next;
            }
        }

        return head;
    }
};
