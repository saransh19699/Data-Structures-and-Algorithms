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
    TreeNode* flatten_rec(TreeNode* root){
        TreeNode* right = root->right;
        root->right = NULL;
        
        if (root->left){
            root->right = flatten_rec(root->left);
            root->left = NULL;
        }
        TreeNode* temp = root;
        while(temp->right) temp = temp->right;
        
        if (right) temp->right = flatten_rec(right);
        return root;
        
    }
    
    void flatten_morris(TreeNode* root){
        while(root){
            if (root->left){
                TreeNode* temp = root->left;
                while(temp->right) temp = temp->right;
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }else{
                root = root->right;
            }
        }
    }
public:
    void flatten(TreeNode* root) {
        // if (root) flatten_rec(root);
        if (root) flatten_morris(root);
    }
};
