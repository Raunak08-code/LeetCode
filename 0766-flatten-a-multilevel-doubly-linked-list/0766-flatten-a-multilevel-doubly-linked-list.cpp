class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        
        // if(temp->child != NULL && temp->next == NULL){
        //     temp->next = temp->child;
        //     temp->child->prev = temp;
        //     temp->child = NULL;
        // }
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