//Approach 2
//Efficient solution by taking a pair of height and balanced

//Time complexity: O(N)
//Space complexity: O(N)

class pair1{
    public:
    int height;
    bool balanced;
};
class Solution {
public:
    pair1 checkBalanced(TreeNode* root){
        pair1 p;
        if(root==NULL){
            p.height=0;
            p.balanced=true;
            return p;
        }
        pair1 left=checkBalanced(root->left);
        pair1 right=checkBalanced(root->right);
        
        p.height=1+max(left.height,right.height);
        if(abs(left.height-right.height)<2 and left.balanced and right.balanced){
            p.balanced=true;
        }
        else{
            p.balanced=false;
        }
        return p;
    }
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root).balanced;
    }
};