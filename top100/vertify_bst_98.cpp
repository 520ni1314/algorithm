#include <climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 传入当前节点，及其范围
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long long lower, long long upper){
        // 自顶向下的思想
        if(root == nullptr){
            return true;
        }
        // 当前节点在范围内才可以，否则为假
        if(root->val <= lower || root->val >= upper){
            return false;
        }
        // 不断缩小范围比较
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
};