class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // move fast n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // if deleting first node
        if(fast == NULL){
            return head->next;
        }

        // move both until fast reaches last node
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // remove nth node
        slow->next = slow->next->next;

        return head;
    }
};
