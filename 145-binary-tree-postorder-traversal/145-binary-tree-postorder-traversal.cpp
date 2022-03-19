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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> v;
        if(root==NULL){
            return v;
        }
        while(!s.empty()){
            TreeNode* cur=s.top();
            s.pop();
            v.push_back(cur->val);
            if(cur->left){
                s.push(cur->left);
            }
            if(cur->right){
                s.push(cur->right);
            }
            
        }
        reverse(v.begin(),v.end());
        return v;
    }
};