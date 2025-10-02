class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* x = new ListNode(0); 
        ListNode* x1 = x;
        ListNode* y = new ListNode(-1);
        ListNode* y1 = y;
        ListNode* temp = head;
        while(temp){
        // x is odd..
            x1->next = temp;
            temp = temp->next;
            x1 = x1->next;
        //y is even..
            y1->next = temp;
            if(temp) temp = temp->next;
            y1 = y1->next;
        }
        x1->next = NULL;
        x = x->next;
        y = y->next;
        ListNode* a = x;
        while(a->next){
            a = a->next;
        }
        a->next = y;
        head = x;
        return head;
    }
};