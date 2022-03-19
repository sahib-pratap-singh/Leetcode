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
        while(root){
            if(root->left){
                TreeNode* pre=root->left;
                while(pre->right && pre->right!=root)
                    pre=pre->right;
                
                if(pre->right==NULL){
                    pre->right=root;
                    root=root->left;
                }
                else{
                    ans.push_back(root->val);
                    pre->right=NULL;
                    root=root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};