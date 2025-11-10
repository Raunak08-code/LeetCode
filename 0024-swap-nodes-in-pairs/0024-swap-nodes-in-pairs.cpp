// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* temp = head;
//         ListNode* hold = NULL;
//         head= temp->next;
//         while(temp && temp->next){
//             hold = temp->next;
//             temp->next = hold->next;
//             hold->next = temp;
//             if(temp->next || temp->next->next) temp->next = temp->next->next;
//             else break;
//             temp = temp->next;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* hold = NULL;

        head = temp->next;  // new head after first swap

        while (temp != NULL && temp->next != NULL) {

            hold = temp->next;          // second node of pair
            ListNode* nextPair = hold->next;   // save start of next pair

            // swap
            hold->next = temp;
            temp->next = nextPair;

            // connect to next swapped pair
            if (nextPair != NULL && nextPair->next != NULL)
                temp->next = nextPair->next;
            else
                break;

            temp = nextPair;
        }

        return head;
    }
};

