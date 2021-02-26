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
    int DFS(TreeNode* root) {
        if(!root)   return 0;
        int left_nodes = DFS(root->left);
        int right_nodes = DFS(root->right);
        return left_nodes + right_nodes + 1;
    }
    int countNodes(TreeNode* root) {
        return DFS(root);
    }
};