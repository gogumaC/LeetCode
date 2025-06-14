/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) a>b?a:b


int divideAndConquere(struct TreeNode* root, int depth){

    if(root->left==NULL && root->right ==NULL) return depth;
    int left=depth;
    int right =depth;

    if(root->right!=NULL) left = divideAndConquere(root->right,depth+1);
    if(root->left!=NULL) right = divideAndConquere(root->left,depth+1);
    //printf("-->d: %d r: %d %d l: %d %d\n",depth,r_res,right,l_res,left);
    if(left<0 || right<0 ||abs(left-right)>1) return -1;
    else return MAX(left,right);
}



bool isBalanced(struct TreeNode* root) {
    if(root==NULL) return true;
    //printf("%d ,%d\n",res, depth);
    return divideAndConquere(root,0)>=0;
}