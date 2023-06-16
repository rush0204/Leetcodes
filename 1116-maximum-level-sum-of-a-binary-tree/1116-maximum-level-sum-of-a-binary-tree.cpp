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
    int maxLevelSum(TreeNode* root) {
        int ans = -1;
        int lvl = 0;
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            lvl++;
            for(int i = 0;i<size;i++){
                TreeNode* top1 = q.front();
                sum+=top1->val;
                if(top1->left){
                   q. push(top1->left);
                }
                if(top1->right){
                    q.push(top1->right);
                }
               q.pop();
            }
            if(sum>maxSum){
                maxSum = sum;
ans = lvl;
            }
        }
        return ans;
    }
};