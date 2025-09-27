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
// // two pointer.
//     ListNode* slow= head;
//     ListNode* fast = head;

//     for(int i=1; i<=n+1; i++){
//         if(fast = NULL)  return head->next;
//         fast = fast->next;  
//     } 
//     while(fast != NULL){
//         slow = slow->next;
//         fast = fast->next;
//     }
//     slow->next= slow->next->next;
//     return head; 


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

        ListNode* temp = head;
        for(int i =1; i<sizee-n; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;   
        return head;
     }
};