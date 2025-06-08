/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Node{
    struct TreeNode* tn;
    uint16_t depth;
    struct Node* next;
}Node;

typedef struct Q{
    Node* front;
    Node* end;
}Q;



Node* createNode(struct TreeNode* tn, uint16_t d){
    Node* n = malloc(sizeof(Node));
    n->tn = tn;
    n->depth = d;
    n->next =NULL;
    return n;
}

void push(Q* q, Node* new){

    if(!q->front){
        q->front = new;
    }
    if(!q->end){
        q->end = new;
        return;
    }
    q->end->next = new;
    q->end= new;
}

Node* pop(Q* q){
    Node* res;
    if(!q->front){
        return NULL;
    }

    res = q->front;
    if(q->front==q->end){
        q->front = NULL;
        q->end = NULL;
    }else{
        q->front = q->front->next;
    }

    return res;
}


int maxDepth(struct TreeNode* root) {
    if(!root) return 0;

    Q q;
    push(&q,createNode(root,1));
    
    uint16_t max = 0;

    while(true){
        Node* c = pop(&q);
        if(!c) break;
        struct TreeNode* tc = c->tn;
        uint16_t depth = c->depth;

        //printf("%d - %d\n",tc->val,depth);
        
        max = max<depth?depth:max;
        if(tc->left) push(&q, createNode(tc->left, depth+1));
        if(tc->right) push(&q, createNode(tc->right, depth+1));
        
        free(c);
    }
    return max;
    
    
}