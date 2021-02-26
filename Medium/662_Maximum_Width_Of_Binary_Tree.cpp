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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) 
            return 0;
        long max_width = 0;
        queue<pair<TreeNode*, long>> q;
        q.push(pair<TreeNode*, long>(root, 1));
        while (!q.empty()) {
            long l = q.front().second, r = l; // right started same as left
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(pair<TreeNode*, int>(node->left, r * 2));
                if (node->right) q.push(pair<TreeNode*, int>(node->right, r * 2 + 1));
            }
            max_width = max(max_width, r + 1 - l);
        }
        return max_width;
    }
};