class Solution {
public:
// this fun is for murging to lists/....
    ListNode* marge(ListNode* list1, ListNode* list2){
        if(list1==NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* a= list1;
        ListNode* b= list2;
        ListNode* c = new ListNode(100);
        ListNode* tc = c;

        while(a != NULL && b != NULL){
            if(a->val <= b->val){
                ListNode* t = new ListNode(a->val);
                tc->next = t;
                tc = t;
                a = a->next;
            }
            else{
                ListNode* t = new ListNode(b->val);
                tc->next = t;
                tc = t;
                b = b->next;
            }
        }
        if(a == NULL) tc->next = b;
        else tc->next = a;
        return c->next;

    }
// this is the main taks we have to do 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        while(lists.size() > 1){
        // here we take first 2 elements from vector and then merge them , again take 2 and murge them  till the size becpome 1.......
            ListNode* a = lists[0];
            lists.erase(lists.begin()); //deleting from start in array
            ListNode* b = lists[0];
            lists.erase(lists.begin());

            ListNode* x = marge(a,b); //calling murge function
            lists.push_back(x); // adding the murgect arrage back to the original vector ... 
        }
        return lists[0]; 
    }
};