#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//创建链表，从头部插入
struct ListNode* construct_linklist(int* nums,int numsSize){
    struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
    head->val = nums[numsSize-1];
    head->next = NULL;
    for(int i=numsSize-2;i>=0;i--){
        struct ListNode* p = (struct ListNode* )malloc(sizeof(struct ListNode));
        p->val = nums[i];
        p->next = head;
        head = p;
    }
    return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *guard=(struct ListNode*)malloc(sizeof(struct ListNode ));
    struct ListNode *p, *p1;
    guard->next = head;
    p = guard;
    p1 = guard;
    int count = 0;
    while(p!=NULL){
        p = p->next;
        count = count+1;
        if(count > n+1){
            p1 = p1->next;
        }
    }
    if(p1->next == head){
        head = head->next;
    }
    else{
        p1->next = p1->next->next;
    }
    return head;
}

//打印链表
void print_linklist(struct ListNode* head){
    struct ListNode* p = head;
    while(p!=NULL){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}
int main(){
    //创建链表，从头部插入
    int nums[5] = {1,2,3,4,5};
    struct ListNode* head = construct_linklist(nums,5);

    //打印链表
    print_linklist(head);

    //删除节点
    removeNthFromEnd(head,2);

    //打印链表
    print_linklist(head);
}
