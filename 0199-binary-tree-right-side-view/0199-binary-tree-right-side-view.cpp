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
map<int,TreeNode*> map;
void level(TreeNode* root,int lvl){
    if(root==NULL){
        return;
    }
    map[lvl] = root;
    level(root->left,lvl+1);
    level(root->right,lvl+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        level(root,0);
       for(auto i : map){
          ans.push_back(i.second->val);
       }
return ans;
    }
};