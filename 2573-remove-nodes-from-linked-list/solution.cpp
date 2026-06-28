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

    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;

        while(head){

            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {

        // reverse list
        head = reverse(head);

        int max = head->val;
        ListNode* curr = head;

        while(curr && curr->next){

            if(curr->next->val < max){

                curr->next = curr->next->next;   // delete
            }
            else{

                curr = curr->next;
                max = curr->val;
            }
        }

        // reverse back
        return reverse(head);
    }
};
