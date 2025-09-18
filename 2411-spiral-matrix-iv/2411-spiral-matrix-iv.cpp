/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> > arr(m,vector<int> (n,-1));
        int rmin = 0;
        int rmax = m-1;
        int cmin = 0;
        int cmax = n-1;

        ListNode* temp = head;

        while(rmin<=rmax && cmin<=cmax){
            for(int i=cmin; i<=cmax; i++){
                if(temp == NULL) return arr;
                arr[rmin][i] = temp->val;
                temp = temp->next;
            }
            for(int i=rmin+1; i<=rmax; i++){
                if(temp == NULL) return arr;
                arr[i][cmax] = temp->val;
                temp = temp->next;
            }
            for(int i=cmax-1; i>=cmin; i--){
                if(temp == NULL) return arr;
                arr[rmax][i] = temp->val;
                temp = temp->next;
            }
            for(int i=rmax-1; i>rmin; i--){
                if(temp == NULL) return arr;
                arr[i][cmin] = temp->val;
                temp = temp->next;
            }
            rmin++;
            rmax--;
            cmin++;
            cmax--;
        }
        return arr;
    }
};