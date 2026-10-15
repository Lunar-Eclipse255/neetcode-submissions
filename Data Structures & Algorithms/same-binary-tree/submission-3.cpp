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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return 1;
        }
        else if (p && q && p->val == q->val){
            bool left_check = isSameTree(p->left, q->left);
            bool right_check = isSameTree(p->right, q->right);
            return left_check && right_check;
        }
        else {
            return 0;
        }
    }
};
