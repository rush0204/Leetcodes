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
int minm(TreeNode* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL){
           return root;
       }
       if(root->val==key){
           //leaf
           if(root->left==NULL&&root->right==NULL){
               delete(root);
               return NULL;
           }
           //one child
           if(root->left!=NULL&&root->right==NULL){
               TreeNode* temp = root->left;
               delete(root);
               return temp;
           }
           if(root->right!=NULL&&root->left==NULL){
               TreeNode* temp = root->right;
               delete(root);
               return temp;
           }
           // two children
           if(root->left!=NULL&&root->right!=NULL){
              int mini = minm(root->right);
              root->val = mini;
              root-> right = deleteNode(root->right,mini); 
           }

       }
       if(key>root->val){
         root->right = deleteNode(root->right,key);
         
       }
       else if(key<root->val){
         root->left =  deleteNode(root->left,key);
       }
       return root;
    }
};