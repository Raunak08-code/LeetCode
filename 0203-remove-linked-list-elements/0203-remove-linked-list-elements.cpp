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
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        if (head == NULL) return NULL;

        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
