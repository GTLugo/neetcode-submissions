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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results{};

        inorderRecurse(root, results);

        return results;
    }

    void inorderRecurse(TreeNode* root, vector<int>& results) {
        if (root == nullptr) {
            return;
        }

        inorderRecurse(root->left, results);
        results.push_back(root->val);
        inorderRecurse(root->right, results);
    }
};