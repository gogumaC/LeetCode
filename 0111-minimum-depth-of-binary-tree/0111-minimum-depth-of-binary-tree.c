/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
typedef struct Node{
    TreeNode* tn;
    int depth;
    struct Node* next;
}Node;
typedef struct Queue{
    Node* front;
    Node* end;
    int len;

}Queue;

bool isEmpty(Queue* q){
    return q->len==0;
}

void append(Queue* q, TreeNode* tn,int depth){
    Node* new = malloc(sizeof(Node));
    if(!new){
        printf("cannot malloc \n");
        return;
    }


    new->tn = tn;
    new->depth = depth;
    if(isEmpty(q)){
        q->front = new;
    }
    if(!isEmpty(q)){
        q->end->next = new;
    }
    q->end = new; 
    q->len++;
}
Node* popleft(Queue* q){
    if(isEmpty(q)){
        return NULL;
    }
    Node* result = q->front;
    q->front = q->front->next;
    q->len--;
    return result;
}

void initQueue(Queue* q){
    q->front =NULL;
    q->end = NULL;
    q->len =0;
}
int minDepth(struct TreeNode* root) {

    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    Queue q;
    initQueue(&q);
    append(&q, root,1);

    while(!isEmpty(&q)){
        Node* n = popleft(&q);
        
        TreeNode* left = n->tn->left;
        TreeNode* right = n->tn->right;
        int depth = n->depth;
        if(!left && !right) return depth;
        if((left && !left->left && !left->right) ||(right && !right->left && !right->right)){
            return depth+1;
        } 

        if(left){
            append(&q,left, depth+1);
        }
        if(right){
            append(&q,right,depth+1);
        }
        free(n);

    }
    return 0;
    
}