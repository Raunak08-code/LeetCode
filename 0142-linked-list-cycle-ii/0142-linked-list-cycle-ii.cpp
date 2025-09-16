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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        vector<ListNode*> v;

        while(temp != NULL){
            v.push_back(temp);
            temp = temp->next;
            for(int i=0; i<v.size(); i++){
                if(temp == v[i]) return temp;
            }
        }
        return NULL;




        // ListNode* slow = head;
        // ListNode* fast = head;

        // while(fast != NULL && fast->next != NULL){
        //     slow= slow->next;
        //     fast = fast->next->next;

        //     if(slow == fast) return slow->next;
        // }
        // return NULL;
    }
};