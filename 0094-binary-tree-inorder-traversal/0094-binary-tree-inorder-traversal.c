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

typedef struct stack{
    int size;
    struct TreeNode* arr[100];
    int last;
}stack;

void init_st(stack* s,int size){
    s->size=size;
    s->last=-1;
}

void push(stack* s, struct TreeNode* n){
    if(s->last+1 == s->size) return;
    s->arr[++(s->last)]=n;
}

struct TreeNode* pop(stack* s){
    if(s->last<0) return NULL;
    return s->arr[s->last--];
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    stack s={0};
    init_st(&s,100);

    int *res=malloc(sizeof(int)*100);
    int idx =0;

    struct TreeNode* current = root;
    while(current || s.last>=0){

        while(current){
            push(&s,current);
            current = current->left;
        }

        current =pop(&s);
        res[idx++] =current->val;

        current = current->right;
                 
       
    }

    *returnSize = idx;

    return res;
    
}