/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {          /*空间复杂度为O（1）*/
    struct ListNode *head2 = head;
    struct ListNode *p = head;
    struct ListNode *q;
    int val;
    while(p!=NULL){
        if(p == head){
            head2 = p;                   /*先建立链表head2的头节点*/
            p = p->next;
            head2->next = NULL;    
        }else{
            q = p->next; 
            p->next = head2; /*后续节点采用栈式链表，将新的节点添加到链表的头部，在链表head遍历的过程中，同时进行链表head2节点的添加，最终完成反转*/
            head2 = p;
            p = q;
        }
    }
    return head2;     
}
