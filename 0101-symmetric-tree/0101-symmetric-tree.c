/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkSymmetric(struct TreeNode *n1,struct TreeNode *n2){
    if(n1==n2) return true;
    if(n1==NULL || n2==NULL) return false;
    if (n1->val == n2->val){
        return checkSymmetric(n1->left, n2->right) && checkSymmetric(n1->right , n2->left);
    }
    return false;
    
}
bool isSymmetric(struct TreeNode* root) {
    if(!root) return true;

    return checkSymmetric(root->left, root->right);
    
}