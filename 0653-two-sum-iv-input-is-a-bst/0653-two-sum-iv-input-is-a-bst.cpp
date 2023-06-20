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
vector<int> sol;
void make(TreeNode* root){
    if(root==NULL){
        return;
    }
    make(root->left);
    sol.push_back(root->val);
    make(root->right);
}
    bool findTarget(TreeNode* root, int k) {
     make(root);
     int a = 0;
     int b = sol.size() -1;
     while(a<b){
         int target = sol[a]+sol[b];
         if(target==k){
             return true;
         }
         if(target>k){
             b--;
         }
         if(target<k){
             a++;
         }
         
     }
     return false;
    }
};