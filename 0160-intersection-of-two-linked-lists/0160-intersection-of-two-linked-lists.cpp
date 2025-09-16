/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int size(ListNode* head){
        ListNode* temp = head;
        int x=0;
        while(temp != NULL){
            x++;
            temp = temp->next;
        }
        return x;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int sizeA = size(tempA);
        int sizeB = size(tempB);

        if(sizeA > sizeB){
            int z = sizeA-sizeB;
            for(int i =0; i<z; i++){
                tempA= tempA->next;
            }
            while(tempA != NULL && tempB != NULL){
                if(tempA == tempB) return tempA;
                tempA= tempA->next;
                if(tempA == tempB) return tempA;
                tempB= tempB->next;   
            }
        }

        else if(sizeA < sizeB){
            int z = sizeB-sizeA;
            for(int i =0; i<z; i++){
                tempB= tempB->next;
            }
            while(tempA != NULL && tempB != NULL){
                if(tempA == tempB) return tempA;
                tempA= tempA->next;
                if(tempA == tempB) return tempA;
                tempB= tempB->next;   
            }
        }
        else{
            while(tempA != NULL && tempB != NULL){
                if(tempA == tempB) return tempA;
                tempA= tempA->next;
                tempB= tempB->next;    
            }
        }
        return NULL;
    }
};