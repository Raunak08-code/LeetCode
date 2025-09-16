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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* b = head->next;
        ListNode* a = head;

        while(b != NULL){
            while(b != NULL && b->val == a->val) {
                b = b->next;
            }
            a->next = b; 
            a = b;
            if(b != NULL) b = b->next;
        }

        // a = a->next;
        // while(b != NULL){
            
        //     if( a == b){
        //         a = b->next->next;
        //         b->next=  b->next->next;
        //         b = b->next;
        //         if(b->next == NULL) return head;
        //         continue;
        //     }
        //     a = a->next; //  
        //     b = b->next; 
        // }
        return head;
    }
};