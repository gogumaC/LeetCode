/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* current = NULL;

    struct ListNode* head =NULL;
    bool up_flag=false;
    while(l1 || l2 || up_flag){

        uint8_t sum = (l1?l1->val:0) + (l2?l2->val:0) + (up_flag?1:0);
        printf("%d ",sum);
        up_flag = false;

        if(sum>=10){
            up_flag=true;
        }
        struct ListNode* new = malloc(sizeof(struct ListNode));
        new->next=NULL;
        new->val = sum%10;
        if(current)current->next = new;
        current=new;
        if(!head) head=current;
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;
        // printf("%d ",current->val);

    }

    return head;
    
}