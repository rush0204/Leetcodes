/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void find(TreeNode* root, TreeNode* p,stack<TreeNode*> &st){
    st.push(root);
    if(root->val==p->val){
       return;
    }
    else if(root->val>p->val){
        find(root->left,p,st);
    }
     else if(root->val<p->val){
        find(root->right,p,st);
    }

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1; 
         find(root,p,st1);
        stack<TreeNode*> st2;
        find(root,q,st2);
       int minSize = min(st1.size(),st2.size());
       cout<<minSize;
        if(minSize<st2.size()){
            cout<<"pop1"<<endl;
            while(st2.size()!=minSize){
                st2.pop();
            }
        }
         if(minSize<st1.size()){
              cout<<"pop2"<<endl;
            while(st1.size()!=minSize){
                st1.pop();
            }
        }
        for(int i = 0;i<minSize;i++){
            TreeNode* fr1 = st1.top();
            TreeNode* fr2 = st2.top();
            if(fr1->val==fr2->val) return fr1;
            st1.pop();
            st2.pop();
        }
        return root;
    }
};