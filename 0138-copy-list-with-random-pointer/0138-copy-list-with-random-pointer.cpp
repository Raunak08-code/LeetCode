class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a dummy list without random thing....
        Node* temp = head;
        Node* dummy = new Node(0);
        Node* td = dummy;
        while(temp){
            Node* a = new Node(temp->val);
            //a = temp;
            td->next = a;
            td = td->next;
            temp = temp->next;
        }

        // merging both original and dummy list.....
        // alternate comnnections......
        Node* duplicate = dummy->next;
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(-1);
        Node* tD = dummy;
        while(a){
           tD->next = a;
           a = a->next;
           tD = tD->next;
           tD->next = b;
           b = b->next;
           tD = tD->next;
        }
        dummy = dummy->next;

        // asing random pointer...
        Node* t1 = dummy; // t1 will traveerse in origional list...
        // Node* t2; 
        while(t1){
            Node* t2 = t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;
        }

        // make new list without duplicateee......
        Node* t= dummy;
        Node* d1 = new Node(-1);
        Node* ta = d1;
        Node* d2 = new Node(-1);
        Node* tb = d2;

        while(t){
            ta->next = t;
            t = t->next;
            ta = ta->next;

            tb->next = t;
            t = t->next;
            tb = tb->next;
        }
        ta->next = NULL;
        tb->next = NULL;

        d1 = d1->next; // original with random
        d2 = d2->next; //  

        return d2;
    }
};