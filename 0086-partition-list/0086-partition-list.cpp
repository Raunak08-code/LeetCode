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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* a = head;

        ListNode* c = new ListNode(100); 
        ListNode* tc = c;

        ListNode* d = new ListNode(100); 
        ListNode* td = d;

        while(a != NULL){
            if(a->val< x){
                tc->next =a;
                a= a->next;
                tc = tc->next;
            }
            else{
                td->next =a;
                a= a->next;
                td = td->next;
            }
        }
        if(a == NULL) td->next = NULL;
        tc->next = d->next;
        return c->next;
    }
};