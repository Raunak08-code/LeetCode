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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* secondTail = head;
        if(head == NULL || head->next == NULL) return head;
        int n= 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        if(k>n) k= k%n;

        for(int i=0; i<k; i++){
            while(secondTail->next->next != NULL){
                secondTail = secondTail->next;
            }

            secondTail->next->next = head; 
            head = secondTail->next;
            secondTail->next = NULL;
            secondTail = head;
        }
        return head;
        
    }
};