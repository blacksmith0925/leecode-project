#include <stdio.h>
#include <malloc.h>
#include <math.h>
/*在addTwoNumbers函数的实现部分摆脱了int或者long int的限制，通过了leetcode，并且速度很快*/

struct ListNode {
    long long int val;
    struct ListNode *next;
    };
struct ListNode *add_to_list(struct ListNode* head,long long int num){
    head->val = num - num/10*10;
    head->next = NULL;
    num = num/10;
    struct ListNode *tail = head;
    while(num != 0){
        struct ListNode *pa = (struct ListNode *)malloc(sizeof(struct ListNode));
        pa->next=NULL;
        pa->val = num - num/10*10;
        tail->next = pa;
        tail = pa;
        num = num/10;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p,*q;

    p = l1;
    q = l2;
    long long int num1 = 0,num2=0,sum=0,flag=0;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    while(p!=NULL||q!=NULL){
        if(p==NULL){
            num1 = 0;
        }else{
            num1 = p->val;
        }
        if(q==NULL){
            num2 = 0;
        }else{
            num2 = q->val;
        }
        sum = num1 +num2+flag;
        if(sum>=10){
            sum = sum-10;
            flag = 1;
        }else{
            flag = 0;
        }
        if(p==l1 && q==l2){
            head ->val = sum;
            head ->next = NULL;
        }else{
            struct ListNode *pa = (struct ListNode *)malloc(sizeof(struct ListNode));
            pa->val = sum;
            pa ->next = NULL;
            tail->next = pa;
            tail = pa;
        }
        if(p!=NULL){
            p = p->next;
        }
        if(q!=NULL){
            q = q->next;
        }
    }
    if(flag ==1){
        struct ListNode *pa = (struct ListNode *)malloc(sizeof(struct ListNode));
        pa->val = 1;
        pa ->next = NULL;
        tail->next = pa;
        tail = pa;
    }
    return head;
}

int main(){
    struct ListNode* head1,*head2;

    head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 = add_to_list(head1,342);

    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2 = add_to_list(head2,465);

    struct ListNode* head3 =  addTwoNumbers(head1,head2);
    struct ListNode* p =head3;
    while(p!=NULL){
        printf("%lld",p->val);
        p=p->next;
    }

    /*删除链表*/
    p= head1;
    while(p!=NULL){
        head1 = p->next;
        free(p);
        p = head1;
    }
    free(head1);
    p = head2;
    while(p!=NULL){
        head2 = p->next;
        free(p);
        p = head2;
    }
    free(head2);
    p = head3;
    while(p!=NULL){
        head3 = p->next;
        free(p);
        p = head3;
    }
    free(head3);

    return 0;
}
