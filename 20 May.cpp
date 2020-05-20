// Using the property of inorder traversal which is sorted for BST
class Solution {
public:
    int node_cnt, ans;

    void helper(TreeNode* root, int k)
    {
        if (root == NULL) return;

        helper(root->left, k);

        node_cnt++;
        if (node_cnt == k) {
            ans = root->val;
            return;
        }

        helper(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        node_cnt = 0;
        helper(root, k);

        return ans;
    }
};
