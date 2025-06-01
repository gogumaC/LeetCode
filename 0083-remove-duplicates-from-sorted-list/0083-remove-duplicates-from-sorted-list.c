/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    if(!head) return NULL;

    struct ListNode* c = head;

    while(c && c->next){
       if(c->val == c->next->val){
        struct ListNode* tmp =c->next->next;
        free(c->next);
        c->next = tmp;
       }else{
        c= c->next;
       }
    }

    return head;
    
}