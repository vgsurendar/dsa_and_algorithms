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

    return (count + 1 + countNodes(root->left) + countNodes(root->right));
 }

 void traverse (struct TreeNode* root, int* idx, int* arr) {
    if (root == NULL) {
        return;
    }

    arr[(*idx)++] = root->val;
    traverse(root->left, idx, arr);
    traverse(root->right, idx, arr);

    return;
 }

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int idx = 0;

    *returnSize = countNodes(root);

    int* res = (int*)malloc(*returnSize * sizeof(int));

    traverse(root, &idx, res);

    return res;
}