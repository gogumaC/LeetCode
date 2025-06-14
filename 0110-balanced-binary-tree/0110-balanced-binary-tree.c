/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) a>b?a:b


int divideAndConquere(struct TreeNode* root, int depth, bool* res){

    if(root->left==NULL && root->right ==NULL) return depth;
    bool l_res,r_res;
    l_res =true; r_res=true;
    int left=depth;
    int right =depth;

    if(root->right!=NULL) left = divideAndConquere(root->right,depth+1,&l_res);
    if(root->left!=NULL) right = divideAndConquere(root->left,depth+1,&r_res);
    printf("-->d: %d r: %d %d l: %d %d\n",depth,r_res,right,l_res,left);
    if(!r_res || !l_res ||abs(left-right)>1) *res = false;
    return MAX(left,right);
}



bool isBalanced(struct TreeNode* root) {
    if(root==NULL) return true;
    bool res=true;
    int depth =divideAndConquere(root,0,&res);
    printf("%d ,%d\n",res, depth);
    return res;
}