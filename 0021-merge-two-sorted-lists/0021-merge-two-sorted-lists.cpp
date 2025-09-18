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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 ==NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* ta= list1;
        ListNode* tb= list2;

        ListNode* c = new ListNode(100);
        ListNode* tc = c;

        while(ta != NULL && tb != NULL){
            if(ta->val <= tb->val){
                ListNode* t = new ListNode(ta->val);
                tc->next = t;
                tc = t;
                ta = ta->next;
            }
            else{
                ListNode* t = new ListNode(tb->val);
                tc->next = t;
                tc = t;
                tb = tb->next;
            } 
        }
        if(ta == NULL) tc->next = tb;
        else tc->next = ta;
        return c->next;
    }
};