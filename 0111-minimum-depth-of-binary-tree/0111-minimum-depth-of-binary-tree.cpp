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
int minD(TreeNode* root){
       if(root==NULL){
            return 0;
        }
      int m1 = minD(root->left);
      int m2 = minD(root->right);
      if(m1==0&&m2==0){
          return 1;
      }
      if(m1!=0&m2==0){
          return m1+1;
      }
       if(m2!=0&m1==0){
          return m2+1;
      }
      return min(m1,m2)+1;
     
    }

    int minDepth(TreeNode* root) {
     int ans = minD(root);
     return ans;
     }
    
};