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
    ListNode* middleNode(ListNode* head) {

// one pass method
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

        // ListNode* temp = head;
        // int n =0;
        // while(temp->next != NULL){
        //     n++;
        //     temp = temp->next;
        // }

        // int middle = n/2;
        // ListNode* trav= head;
        // if(n%2==0){
        //     for(int i =0; i<middle; i++){
        //         trav = trav->next;
        //     }
        // }
        // else{
        //     for(int i =0; i<=middle; i++){
        //         trav = trav->next;
        //     }
        // }
        // // for(int i =0; i<=n/2; i++){
        // //         trav = trav->next;
        // // }
        // return trav;
    }
};