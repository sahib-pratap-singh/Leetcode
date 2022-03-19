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
class Pair{
    public:
    int height;
    int diameter;
};
class Solution {
public:
    Pair diam(TreeNode* root){
        Pair p;
        if(root==NULL){
            p.height=0;
            p.diameter=0;
            return p;
        }
        Pair left=diam(root->left);
        Pair right=diam(root->right);
        p.height=1+max(left.height,right.height);
        p.diameter=max((left.height+right.height),max(left.diameter,right.diameter));
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Pair p=diam(root);
        return p.diameter;
    }
};