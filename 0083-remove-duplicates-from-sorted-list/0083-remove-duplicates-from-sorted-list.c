/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode* c = head;
    struct ListNode* next;

    while(c){
        next= c->next;
        while(c->next && next->val == c->val){
            c->next = next->next;
            free(next);
            next =c->next;
        }
        c = c->next;
    }

    return head;
    
}