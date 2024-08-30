
//Definition for a binary tree node.
#include <vector>
using namespace std;
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
    vector<TreeNode*> arr;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        // 直接返回第k个
        return arr[k-1]->val;
    }
    // 中序遍历BST存储到数组
    void inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
};