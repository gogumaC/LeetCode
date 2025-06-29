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


int res[100]={0};
 int rs =0;

void preorder(struct TreeNode* root){
    if(!root){
        return;
    }
    //printf("%d : val %d\n",rs,root->val);
    res[rs++] = root->val;


    if(root->left){
        preorder(root->left);
    }
    if(root->right){
        preorder(root->right);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    rs=0;
    preorder(root);
    *returnSize = rs;
    
    return res;


}