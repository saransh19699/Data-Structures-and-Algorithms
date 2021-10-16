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
    // long l=(long)INT_MIN-1,
    TreeNode* bstfp(vector<int>& preorder, int& i,  long h=(long)INT_MAX+1){
        if (i == preorder.size()) return NULL;
        TreeNode* node = new TreeNode(preorder[i]);
        
        // while(i < preorder.size() && preorder[i] == node->val) 
            i++;
        
        if (i < preorder.size() && preorder[i] < node->val) 
            node->left = bstfp(preorder, i, node->val);
        
        if (i < preorder.size() && node->val < preorder[i] && preorder[i] < h)
            node->right = bstfp(preorder, i, h);
        
        
        return node;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bstfp(preorder, i);
    }
};
