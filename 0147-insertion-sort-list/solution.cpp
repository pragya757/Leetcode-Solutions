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
    ListNode* insertionSortList(ListNode* head) {

        ListNode* dummy = new ListNode(0);   // sorted list

        ListNode* curr = head;

        while(curr){

            ListNode* next = curr->next;   // save next node

            // find insertion position
            ListNode* prev = dummy;

            while(prev->next && prev->next->val < curr->val){

                prev = prev->next;
            }

            // insert current node
            curr->next = prev->next;
            prev->next = curr;

            // move to next node
            curr = next;
        }

        return dummy->next;
    }
};
