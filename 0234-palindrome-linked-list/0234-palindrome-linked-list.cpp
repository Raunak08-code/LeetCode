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
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* c= new ListNode(10);
        ListNode* tc = c;

        ListNode* temp= head;
        while(temp != NULL){
            ListNode* node = new ListNode(temp->val);
            tc->next= node;
            temp = temp->next;
            tc = tc->next;
        }
        c = c->next;
        ListNode* nh = reverse(c);
        ListNode* a = head;
        ListNode* b= nh;

        while(a != NULL && b != NULL){
            if(a->val != b->val ) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};