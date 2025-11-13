// class Solution {
// public:

//     ListNode* reverse(ListNode* head){
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* nh = reverse(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return nh; 
//     }

//     int size(ListNode* head){
//         int n=0;
//         ListNode* temp = head;
//         while(temp != NULL){ // TC O(n)
//             n++;
//             temp = temp->next;
//         }
//         return n;
//     }

//     // ListNode* reverseKGroup(ListNode* head, int k) {
//     //     ListNode* temp = head;
//     //     ListNode* newhead = temp;
//     //     ListNode* secondHead;
//     //     ListNode* x;
//     //     vector<ListNode*> ListHead;
//     //     while(temp){
//     //         newhead = temp;
//     //         for(int i=0; i<k; i++){
//     //             temp = temp->next;
//     //         }
//     //         if(temp->next!= NULL){
//     //             temp->next = secondHead;
//     //             temp->next = NULL;
//     //         }
//     //         temp->next = NULL;
//     //         ListHead.push_back(newhead);
//     //         temp= secondHead;
//     //     }

//     //     for(int i=0; i<ListHead.size()-1; i++){
//     //         x = ListHead[i];
//     //         ListNode* nh = reverse(x);
//     //         ListHead[i] = nh;
//     //     }

//     //     for(int i=0; i<ListHead.size(); i++){
//     //         x = ListHead[i];
//     //         ListNode* t = x;
//     //         while(t->next){
//     //             t = t->next;
//     //         }
//     //         t->next = ListHead[i+1];
//     //     }

//     //     return ListHead[0];
//     // }

//     // ListNode* reverseKGroup(ListNode* head, int k){
//     //     if(size(head)< k) return head;
//     //     ListNode* temp = head; 
//     //     ListNode* a = head;
//     //     ListNode* b;
//     //     ListNode* c;
//     //     ListNode* t = head;
//     //     ListNode* t2 = NULL;

//     //     // new head for return...  TC O(k)..
//     //     for(int i=0; i<k-1; i++){
//     //         t = t->next;
//     //     }
//     //     t = head;
        
//     //     while(temp->next != NULL){
            
//     //         for(int i=0; i<k-1; i++ ){
//     //             temp = temp->next;
//     //         }
//     //         temp = b;
        
//     //         if(temp->next != NULL)  temp->next = c; 
//     //         b->next = NULL;

//     //         ListNode* nh = reverse(a);
//     //         a->next = c;
            
//     //         t2->next = b;
//     //         t2 = a;
//     //         ////

//     //         if(size(c) < k) return head;
            
//     //             c = a;
//     //             temp = a;
            
//     //     }
//     //     return head;
//     // }

//     ListNode* reverseKGroup(ListNode* head, int k){
//         ListNode* dummy = new ListNode(10);
//         ListNode* d = dummy;
//         ListNode* temp = head;
//         ListNode* a = temp ;
//         ListNode* b = temp;
//         ListNode* c;

//         while(size(temp)-k >= 0){
            
//             while(k-- && b->next != NULL){
//                 temp = temp->next;
//             }
//             temp = b;
//             b->next = c;

//             ListNode* nh = reverse(a);

//             d->next = b;
//             d = b->next;
//             a->next = c;
//             a=c;
//             temp = a;
//         }
//         return dummy->next;
//     }

// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // This is the standard list reversal function you probably have.
    // It reverses a list from 'head' until it hits NULL.
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // 'prev' is the new head
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. Setup
        // Dummy node helps manage the list head easily.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // This points to the TAIL of the PREVIOUS k-group.
        // For the first group, it's the dummy node.
        ListNode* prevGroupTail = dummy;
        
        // 'curr' is our main traversal pointer, starting at the head.
        ListNode* curr = head;

        // 2. Main Loop
        while (curr != nullptr) {
            
            // 3. Find the k-group
            ListNode* groupStart = curr;
            ListNode* groupEnd = curr;
            
            // Try to advance 'groupEnd' k-1 steps to find the
            // end of the current group.
            int count = 1;
            while (count < k && groupEnd != nullptr) {
                groupEnd = groupEnd->next;
                count++;
            }
            
            // If groupEnd is NULL, we don't have k nodes left.
            // The rest of the list stays as is. We're done.
            if (groupEnd == nullptr) {
                break;
            }
            
            // 4. Isolate the group and save the next pointer
            // Save the start of the *next* group.
            ListNode* nextGroupStart = groupEnd->next;
            
            // "Cut" the current k-group from the list.
            groupEnd->next = nullptr;
            
            // 5. Reverse the isolated group
            // 'reverse' will return the new head of this reversed group.
            // The old 'groupEnd' is now the head.
            ListNode* reversedGroupHead = reverse(groupStart);
            
            // 6. Relink the reversed group
            
            // a. Link the previous group's tail to the new group's head.
            prevGroupTail->next = reversedGroupHead; // or 'groupEnd'
            
            // b. Link the new group's tail (which is the old 'groupStart')
            //    to the start of the next group.
            groupStart->next = nextGroupStart;
            
            // 7. Update pointers for the next iteration
            
            // The 'prevGroupTail' for the *next* loop is the
            // tail of the group we just processed (which is 'groupStart').
            prevGroupTail = groupStart;
            
            // The 'curr' for the *next* loop is the start of the
            // next group.
            curr = nextGroupStart;
        }
        
        // 8. Return
        // The dummy's 'next' will point to the head of the
        // fully modified list (which is the head of the first reversed group).
        return dummy->next;
    }
};