#include "head.hpp"

class Solution {
public:
    vector<TreeNode*> vec;
    void flatten(TreeNode* root) {
        pre(root);
        int size = vec.size();
        for(int i=1;i<size; ++i){
            (vec[i-1])->right = vec[i];
            (vec[i-1])->left = nullptr;
            // TreeNode *prev = vec.at(i - 1), *curr = vec.at(i);
            // prev->left = nullptr;
            // prev->right = curr;
        }
        // vec[size-1]->right = nullptr;
        // vec[size-1]->left = nullptr;
    }
    void pre(TreeNode* root){
        if(root == nullptr){
            return;
        }
        vec.push_back(root);
        pre(root->left);
        pre(root->right);
    }

};