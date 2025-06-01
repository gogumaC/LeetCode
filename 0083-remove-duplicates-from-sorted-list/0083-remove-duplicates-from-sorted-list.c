/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    if(!head) return head;

    struct ListNode* c = head;

    while(c && c->next){
       if(c->val == c->next->val){
        c->next = c->next->next;
       }else{
        c= c->next;
       }
    }

    return head;
    
}