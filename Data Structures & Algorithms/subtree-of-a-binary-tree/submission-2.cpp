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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return 1;
        }
        if (!root) {
            return 0;
        }
        if (isSame(root, subRoot)) {
            return 1;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }

    bool isSame (TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return 1;
        }
        if (p && q && p->val == q-> val) {
            return (isSame(p->left, q->left)&& isSame(p->right, q->right));
        }
        else {
            return 0;
        }
    }
};
