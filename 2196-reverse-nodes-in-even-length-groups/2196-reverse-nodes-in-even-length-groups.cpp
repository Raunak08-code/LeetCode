// class Solution {
// public:

// //function for finding size of whatever....
//     int sizee(ListNode* head){
//         int n=0;
//         while(head){
//             n++;
//             head = head->next;
//         }
//         return n;
//     }

// // to do reverse...
//     ListNode* reverse(ListNode* head){
//         if(head== NULL || head->next == NULL) return head;
//         ListNode* nh = reverse(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return nh;
//     }

// // for merger of two list formed from mergeVectorList ...
//     ListNode* merger(ListNode* list1, ListNode* list2){
//         ListNode* a = list1;
//         ListNode* b = list2;
//         while(a->next){
//             a = a->next;
//         }
//         a->next = b;
//         return list1;
//     }

// // merge from vector of heads
//     ListNode* mergreVectorList(vector<ListNode*>& lists){
//         if(lists.size() == 0) return NULL;
//         while(lists.size() > 1){
//             ListNode* a =  lists[0]; //.............//.........//...............//......//
//             lists.erase(lists.begin());
//             ListNode* b= lists[1];
//             lists.erase(lists.begin());

//             ListNode* merge2 = merger(a,b);
//             lists.push_back(merge2);
//         }
//         return lists[0];
//     }

// // grouping....
//     ListNode* reverseEvenLengthGroups(ListNode* head) {
//         ListNode* temp = head;
//         int n = sizee(head);
//         vector<ListNode*> v;       
//         ListNode* x= temp;
//         for(int i=0; i<n; i++){
//             ListNode* c = new ListNode(100);
//             ListNode* tc = c;
//             while(i){
//                 temp = temp->next;
//                 i--;
//                 if(temp == NULL) break;
//             }
//             tc= x; 
//             if(temp == NULL){
//                 v.push_back(tc);
//                 break;
//             }
//             else{
//                 x= temp->next;
//                 temp->next = NULL;
//                 v.push_back(tc);
//                 temp = x;
//             }
             
//         } // by the end of this for loop we will complete our group/;

//         vector<ListNode*> p;
//         for(int i=0; i<v.size(); i++){
//             ListNode* z = v[i];
//             int sg = sizee(z);
//             if(sg%2 == 0){
//                 ListNode* r = reverse(z);
//                 p.push_back(r);
//             }
//             else p.push_back(z);
//         }
//         return mergreVectorList(p);
//     }
// };


class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* nh = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh; 
    }

    // in this method we break our linkedlist into 3 parts i) head to l-1; ii)l to r; iii) r+1 to tail;....
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* a = head;
        ListNode* b = head;
        if(left == 1){ // this if condition is very important becouse here we only break into two parts not three parts ....
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

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while(temp && temp->next){
            int remlen =0;
            ListNode* t = temp->next;
            for(int i=1; i<= gap+1 && t!=NULL; i++){
                t=t->next;
                remlen++;
            }
            if(remlen< gap+1) gap = remlen-1;
            if(gap%2 !=0) reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=1; temp!=NULL && i<=gap; i++){
                temp = temp->next;
            }
        }
        return head;
    }
};