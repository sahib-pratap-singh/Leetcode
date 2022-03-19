//Iterative solution

//Time Complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> nodestack;
        unordered_map<TreeNode*,TreeNode*> parent;
        
        nodestack.push(root);
        parent[root]=NULL;
        
        while(!parent.count(p) || !parent.count(q)){
            TreeNode* cur=nodestack.top();
            nodestack.pop();
            
            if(cur->left!=NULL){
                parent[cur->left]=cur;
                nodestack.push(cur->left);
            }
            if(cur->right!=NULL){
                parent[cur->right]=cur;
                nodestack.push(cur->right);
            }
        }
        
        set<TreeNode*> ancestor;
        while(p!=NULL){
            ancestor.insert(p);
            p=parent[p];
        }
        while(!ancestor.count(q)){
            q=parent[q];
        }
        return q;
    }
};