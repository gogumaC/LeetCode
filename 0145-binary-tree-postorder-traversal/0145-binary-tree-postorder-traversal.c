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

void postOrder(struct TreeNode* root, int* res, int* returnSize){
    if(root->left) postOrder(root->left,res,returnSize);
    if(root->right) postOrder(root->right,res,returnSize);
    res[(*returnSize)++]=root->val;

}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(100*sizeof(int));
    *returnSize = 0;

    if(root) postOrder(root,res,returnSize);
    return res;    
}