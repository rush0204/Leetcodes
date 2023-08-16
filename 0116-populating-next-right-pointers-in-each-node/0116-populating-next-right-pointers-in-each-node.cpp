/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*,int>> q;
        pair<Node*,int> p1 = {root,0};
        q.push(p1);
        while(!q.empty()){
           pair<Node*,int> fr = q.front();
            q.pop();
           if(fr.first!=NULL){
            if(!q.empty()){
                if(q.front().second==fr.second) fr.first->next = q.front().first;
                else fr.first->next = NULL;
           }
           else fr.first->next = NULL;
           q.push({fr.first->left,fr.second+1});
           q.push({fr.first->right,fr.second+1});
           }
          
           

        }
        return root;       
    }
};