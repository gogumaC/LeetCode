/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    

    if(list1==NULL && list2==NULL) return NULL;

    struct ListNode* tail = NULL;
    struct ListNode* start = NULL;

    while(list1!=NULL && list2!=NULL)
    {
        struct ListNode* next = NULL;

        if(list1->val>=list2->val)
        {
            next = list2;
            list2 = list2->next;
        }else
        {
            next = list1;
            list1 = list1->next;
        }
        next->next=NULL;

        if(tail==NULL){
                tail = next;
                start = next;
        }else{       
            tail->next = next;
            tail = next;
        }
    }

    struct ListNode* res = NULL;
    res = (list1==NULL)?list2:list1;

    if(tail==NULL) return res;

    tail->next= res;

    return start;

}