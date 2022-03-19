/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur=root;
        while(!s.empty()){
            while(cur && cur->left){
                s.push(cur->left);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            if(cur!=NULL){
                ans.push_back(cur->val);
                s.push(cur->right);
                cur=cur->right;
            }
        }
        return ans;
    }
};