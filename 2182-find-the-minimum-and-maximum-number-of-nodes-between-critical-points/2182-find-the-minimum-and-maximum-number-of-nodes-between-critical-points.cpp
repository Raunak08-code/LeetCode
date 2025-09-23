// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> v;
//         ListNode* t = head;
//         int n =0;
//         int criticalCount = 0;
//         if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1,-1};
//         while(t->next->next != NULL){
//             n++;
//             if(((t->next->val) > (t->val)) && ((t->next->val) > (t->next->next->val))) { // critical point of maxima..
//                 v.push_back(n+1);
//                 criticalCount++;
//                 t= t->next;
//             }
//             else if(((t->next->val) < (t->val)) && ((t->next->val) < (t->next->next->val))){ // critical point of minima..
//                 v.push_back(n+1);
//                 criticalCount++;
//                 t= t->next;
//             }
//             else{
//                 t= t->next;
//             }    
//         }
//         if(criticalCount <= 1) return {-1,-1};

//         vector<int> v2;
//         for(int i =0; i<v.size(); i++){
//             for(int j=i+1; j<v.size(); j++){
//                 v2.push_back(v[j]-v[i]);
//             }
//         } 
//         int maxDis = 0;
//         int minDis = 10000;  
//         for(int i=0; i<v2.size(); i++){
//             maxDis = max(maxDis,v2[i]);
//             minDis = min(minDis,v2[i]);
//         }
//         vector<int> v3;
//         v3.push_back(minDis);
//         v3.push_back(maxDis);

//         return v3;
//     }
// };


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int n=1;
        int first =-1;
        int last = -1;
        int f=-1;
        int s=-1;
        int minDis = INT_MAX;
    
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        int d=0;

        if(c == NULL) return {-1,-1};
        while(c){
            if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
                if(first == -1) first = n;
                else last = n;

                f=s;
                s=n;
                if(f!= -1){
                    d= s-f;
                    minDis = min(minDis,d);
                }  
            } 
            n++;
                a = a->next;
                b = b->next;
                c = c->next;   
        }
        if(last == -1) return {-1,-1};
        int maxDis = last-first;

        return {minDis,maxDis};
    }
};