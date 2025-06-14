/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) a>b?a:b


int getMaxDepth(struct TreeNode* root, int depth){

    if(root->left==NULL && root->right ==NULL) return depth;
    else if(root->left==NULL) return getMaxDepth(root->right,depth+1);
    else if(root->right ==NULL) return getMaxDepth(root->left,depth+1);
    
    return MAX(getMaxDepth(root->left,depth+1),getMaxDepth(root->right,depth+1));
}

bool isBalanced(struct TreeNode* root) {
    if(root ==NULL) return true;
    else if(root->left==NULL && root->right ==NULL) return true;
    int left=0;
    int right =0;
    if(root->right!=NULL) right = getMaxDepth(root->right,1);
    if(root->left!=NULL) left = getMaxDepth(root->left,1);

    return isBalanced(root->left) && isBalanced(root->right) && abs(left-right)<2;
}