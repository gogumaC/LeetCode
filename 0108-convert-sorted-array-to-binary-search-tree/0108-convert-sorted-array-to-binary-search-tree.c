/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bst( int* nums, int start, int end){
    if(start>end) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    int mid = start+(end-start)/2;
    root->val = nums[mid];
    root->left = bst(nums, start, mid-1 );
    root->right =bst(nums,mid+1,end);


    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {

    return bst( nums,0,numsSize-1);    
}