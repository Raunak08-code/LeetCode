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
    int size(ListNode* head){
        ListNode* temp = head;
        int n=0;
        while(temp){
            n++;
            temp = temp->next;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = size(head);
        if( k >= n ){
            vector<ListNode*> v;
            ListNode* temp = head;
            while(temp){
                ListNode* t = new ListNode;
                t = temp->next;
                temp->next = NULL;
                v.push_back(temp);
                temp = t;  
            }
            if(k>n){
                for(int i=n; i<k; i++){
                    v.push_back(NULL);
                }
            }
            return v;
        }

        vector<ListNode*> v;
        int x= n/k;
        int z= n%k;
        ListNode* temp = head;
        while(temp){
            ListNode* c = new ListNode(100);
            ListNode* tc = c;
            int s= x;
            if(z>0) s++;
            z--;
            for(int i=1; i<=s; i++){
                tc->next = temp;
                temp = temp->next;
                tc = tc->next;
            }
            tc->next = NULL;
            v.push_back(c->next);
        }
        return v;
    }
};