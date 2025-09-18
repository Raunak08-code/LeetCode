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
    ListNode* marge(ListNode* list1, ListNode* list2){
        if(list1==NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* a= list1;
        ListNode* b= list2;
        ListNode* c = new ListNode(100);
        ListNode* tc = c;

        while(a != NULL && b != NULL){
            if(a->val <= b->val){
                ListNode* t = new ListNode(a->val);
                tc->next = t;
                tc = t;
                a = a->next;
            }
            else{
                ListNode* t = new ListNode(b->val);
                tc->next = t;
                tc = t;
                b = b->next;
            }
        }
        if(a == NULL) tc->next = b;
        else tc->next = a;
        return c->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        while(lists.size() > 1){

            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());

            ListNode* x = marge(a,b);
            lists.push_back(x);
        }
        return lists[0]; 
    }
};