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
    int dobt(TreeNode* node, int& diam){ // return height
        if (!node) return 0;
        
        int lh = dobt(node->left, diam);
        int rh = dobt(node->right, diam);
        
        diam = max(diam, lh+1+rh);
        
        return max(lh, rh) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        dobt(root, diam); // this is counting number of nodes in the path
        // path length will be 1 lesser
        return diam-1;
    }
};
