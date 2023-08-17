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
TreeNode* maxm(TreeNode* root){
    while(root->right){
        root=root->right;
    }
    return root;
}
TreeNode* minm(TreeNode* root){
    while(root->left){
        root=root->left;
    }
    return root;
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(root->right&&root->left){
        TreeNode* mini = maxm(root->left);
        TreeNode* maxi = minm(root->right);
        if(mini->val<maxi->val&&mini->val<root->val&&maxi->val>root->val){
            return isValidBST(root->left)&&isValidBST(root->right);
        }else return false;
        }
        else if(root->right){
            TreeNode* maxi = minm(root->right);
            if(maxi->val>root->val){
            return isValidBST(root->left)&&isValidBST(root->right);
        }else return false;
        }
        else if(root->left){
            TreeNode* mini = maxm(root->left);
            if(mini->val<root->val){
            return isValidBST(root->left)&&isValidBST(root->right);
        }else return false;
        }
        else{
            return true;
        }
    }
};