/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int countNodes (struct TreeNode* root) {
    int count = 0;

    if (root == NULL) {
        return count;
    }

    return (count + countNodes(root->left) + 1 + countNodes(root->right));
}

void traverse (struct TreeNode* root, int* idx, int* arr) {
    if (root == NULL) {
        return;
    }

    traverse(root->left, idx, arr);
    traverse(root->right, idx, arr);
    arr[(*idx)++] = root->val;

    return;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {

    int* res = NULL;
    int idx = 0;

    *returnSize = countNodes(root);

    res = (int*)malloc(*returnSize * sizeof(int));

    traverse(root, &idx, res);

    return res;
}