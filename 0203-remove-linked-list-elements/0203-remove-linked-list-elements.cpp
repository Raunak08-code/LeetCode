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
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if(head == NULL) return head; // && head->val == val) return NULL;
//         else if(head->next == NULL){
//             if(head->val == val) return NULL;
//             else return head;
//         }
//         ListNode* temp = head;
//         //if(head->val == val) head = head->next; 
//         while(temp){ 
//             if(head->val == val) head = head->next; 

//             if(temp->next == NULL){
//                 temp = temp->next;
//                 break;
//             }
            
//             else if(temp->next->val == val){
//                 temp->next = temp->next->next;
//             }
//             temp = temp->next;
//         }
//         return head;
//     }
// };




class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Step 1: Skip nodes from the start that have the target value
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        // If the list is empty after removing initial nodes
        if (head == NULL) return NULL;

        // Step 2: Use a pointer to traverse and remove nodes
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next; // skip the node
            } else {
                temp = temp->next; // move forward
            }
        }

        return head;
    }
};
