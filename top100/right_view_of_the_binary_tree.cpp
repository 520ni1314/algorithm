#include <queue>
#include <vector>
using namespace std;
//Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        // 利用层次遍历
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int curLevelNodes = que.size();
            for(int i=0;i<curLevelNodes;i++){
                // 弹出 加左右孩子节点进来
                TreeNode* node = que.front();
                que.pop();
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
                // 该代码位置无关
                if(i == curLevelNodes - 1){     // 只添加当前层最后一个节点
                    ans.push_back(node->val);
                }
            }
        }


        return ans;
    }
};