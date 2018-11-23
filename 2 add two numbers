#include <stdio.h>
#include <malloc.h>
#include <math.h>

/*这种方法存在一个问题，就是当数字位数特别多时，long long int无法表示。造成程序无妨正常运行*/
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
    struct ListNode *p;

    p = l1;
    long long int num1 = 0,count1 = 1;
    while(p!=NULL){
        num1 += (p->val)*count1;
        p = p->next;
        count1 = count1*10;
    }

    p = l2;
    long long int num2 = 0,count2 = 1;
    while(p!=NULL){
        num2 += (p->val)*count2;
        p = p->next;
        count2 = count2*10;
    }

    long long int sum;
    sum = num1+num2;
    printf("%lld\n",sum);
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head ->val = sum - sum/10*10;
    head ->next = NULL;
    sum = sum/10;

    struct ListNode *tail = head;
    while(sum != 0){
        struct ListNode *pa = (struct ListNode *)malloc(sizeof(struct ListNode));
        pa->val = sum - sum/10*10;
        pa ->next = NULL;
        tail->next = pa;
        tail = pa;
        sum = sum/10;
    }
    return head;
}

int main(){
    struct ListNode* head1,*head2;

    head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 = add_to_list(head1,9);

    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2 = add_to_list(head2,9999999991);

    struct ListNode* head3 =  addTwoNumbers(head1,head2);
    struct ListNode* p =head3;
    while(p!=NULL){
        printf("%lld",p->val);
        p=p->next;
    }
    
    return 0;
}
