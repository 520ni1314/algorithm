#include <vector>
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
    // 有序数组构造二叉搜索树 BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return cast(nums, 0, nums.size()-1);
    }
    // 返回子树的根
    TreeNode* cast(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }

        // 中间元素作根
        int mid = (left + right)/2;
        TreeNode* l = cast(nums, left, mid-1);
        TreeNode* r = cast(nums, mid+1, right);
        return new TreeNode(nums[mid],l,r); // 构造节点并连接
    }
};