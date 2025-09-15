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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* terv = head;
        int sizee=0;
        while(terv != NULL){
            sizee++;
            terv = terv->next;
        }
        if(n == sizee){
            head= head->next;
            return head;
        }

        int len = sizee-n+1;
        int m = len-1;

        ListNode* temp = head;
        for(int i =1; i<=m-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;   
        return head;
    }
};