class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* nh = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh; 
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* a = head;
        ListNode* b = head;
        if(left == 1){
            for(int i=1; i<right; i++){
                b = b->next;
            }
            ListNode* x= head;
            // a->next = NULL;
            ListNode* c = b->next;
            b->next = NULL;

            ListNode* z = reverse(x);
            ListNode* temp = z;
            while(temp->next != NULL){
                temp = temp->next;
            }
            head = z;
            temp->next =c;
            return head;
        }
        

        for(int i=1; i<left-1; i++){
            a = a->next;
        }
        
        for(int i=1; i<right; i++){
            b = b->next;
        }

        ListNode* x= a->next;
        a->next = NULL;
        ListNode* c = b->next;
        b->next = NULL;

        ListNode* z = reverse(x);
        ListNode* temp = z;
        while(temp->next != NULL){
            temp = temp->next;
        }
        a->next = z;
        temp->next =c;
        return head;
    }
};