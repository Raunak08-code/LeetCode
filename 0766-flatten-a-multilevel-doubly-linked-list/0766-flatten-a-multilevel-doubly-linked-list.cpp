class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp){
            Node* a = temp->next;
            if(temp->child != NULL){  
                Node* c = temp->child;
                temp->child = NULL; // task given..
                c= flatten(c); // recursion...
                temp->next  = c;
                c->prev = temp;
                while(c->next){
                    c = c->next;
                }
                c->next = a;
                if(a != NULL) a->prev = c;
            }
            temp = a;
        }
        return head;
    }
};