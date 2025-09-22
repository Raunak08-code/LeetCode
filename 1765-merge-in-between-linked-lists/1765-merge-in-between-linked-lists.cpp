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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* x = list1;
        ListNode* y = list1;

        for(int i =1; i<= a-1; i++){
            x= x->next;
        }
        ListNode* x1 = x->next;
        for(int i=1; i<=b; i++){
            y= y->next;
        }
        ListNode* y1= y->next;

        ListNode* tail2 = list2;
        while(tail2->next != NULL){
            tail2 = tail2->next;
        }

        x->next = list2;
        tail2->next =y1;

        return list1;

    }
};