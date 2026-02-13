class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL ) return 0;
        return 1+ max(level(root->left),level(root->right));
    }

    void ntLevel(TreeNode* root,vector<int>& level_n,int source, int destination){
        if(root==NULL) return;
        if(source == destination){
            level_n.push_back(root->val);
            return;
        }
        ntLevel(root->left,level_n, source+1, destination);
        ntLevel(root->right,level_n, source+1, destination);
    }
    
    void l_Order(TreeNode* root , vector<vector<int>>& result) {
        int n = level(root);
        for(int i =1 ;i<=n; i++){
            vector<int> level_n;
            ntLevel(root , level_n , 1 , i);
            result.push_back(level_n);
            cout<<endl;
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        l_Order(root,result);
        return result;
    }
};