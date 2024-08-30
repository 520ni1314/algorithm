#include "head.hpp"
class Solution {
public:


    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        return check(root->left, root->right);
    }
    bool check(TreeNode* q, TreeNode* p){
        // 检查节点值是否相同，相同则相反方向走
        if(q==nullptr && p==nullptr) return true;
        if(q== nullptr || p==nullptr) return false; // 一个空 一个不空
        // 一分为二
        return q->val == p->val && check(q->left,p->right) && check(q->right, p->left);
    }

};