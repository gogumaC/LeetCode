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

    while(c!=NULL && c->next!=NULL){
       if(c->val == c->next->val){
        c->next = c->next->next;
        //free(c->next);
       }else{
        c= c->next;
       }
        

    }

    return head;
    
}