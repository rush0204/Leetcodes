// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         queue<pair<TreeNode*,pair<int,int>>> qwe;
//         map<int,vector<pair<int,int>>> mp;
//      vector<vector<int>> soln;
//         int n = 0;
//         int k = 0;
//             qwe.push({root,{n,k}});
//         while(!qwe.empty()){
//         pair<TreeNode*,pair<int,int>> p1 = qwe.front();
//         qwe.pop();
//         mp[p1.second.first].push_back({p1.first->val,p1.second.second});
//         cout<<"pushed in "<<p1.second.first<<"  ,"<<p1.first->val<<endl;
//        if(p1.first->left){
//            qwe.push({p1.first->left,{p1.second.first-1,p1.second.second+1}});
//        }
//        if(p1.first->right){
//            qwe.push({p1.first->right,{p1.second.first+1,p1.second.second+1}});
//        }
//         }

// for(auto it:mp){
//     vector<int> ress;
//     vector<pair<int,int>> k = it.second;
// sort(k.begin(),k.end());
// for(int i = 0;i<it.second.size();i++){
//     ress.push_back(k[i].first);
//     cout<<"ptint "<<k[i].first<<endl;

// }
// soln.push_back(ress);
// }
// return soln;
//     }
// };
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
    
    map<int,vector<pair<int,int>>>mp;
    void f(int r,int c,TreeNode*root){
        if(!root)return;
        mp[c].push_back({r,root->val});
        f(r + 1,c - 1,root->left);
        f(r + 1,c + 1,root->right);
    }
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first == b.first)return a.second < b.second;
        else return a.first < b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        f(0,0,root);
        for(auto it:mp){
            sort(it.second.begin(),it.second.end(),cmp);
            vector<int>tmp;
            for(auto i:it.second){
                tmp.push_back(i.second);
            }
            res.push_back(tmp);
        }
        return res;
    }
};