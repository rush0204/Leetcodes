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
bool helper(TreeNode* root, long minm, long maxm){
    if(root==NULL) return true;
    if(root->val>minm&&root->val<maxm){
        if(root->left!=NULL&&root->right!=NULL){
        return helper(root->left,minm,root->val)&&helper(root->right,root->val,maxm);
        }
        else if(root->left) return helper(root->left,minm,root->val);
        else if(root->right) return helper(root->right,root->val,maxm);
        else return true;
    }else return false;
}
    bool isValidBST(TreeNode* root) {
        long minm = LONG_MIN;
        long maxm = LONG_MAX;
        return helper(root,minm,maxm);
        
    }
};