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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* nh = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast= head;
        ListNode* a  = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverse(slow->next);
        slow->next = NULL;
        while(a && b){
            ListNode* x = new ListNode;
            x= a->next;
            ListNode* y = new ListNode;
            y= b->next;

            a->next = b;
            b->next = x;
            if(a->next->next == NULL){
                ListNode* temp = head;
                while(temp){
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
            }
            a = x;
            b = y;
        }
        ListNode* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};