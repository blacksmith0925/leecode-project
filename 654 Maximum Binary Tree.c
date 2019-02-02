#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void get_max_num(int* nums,int pos_start,int pos_end,int* max,int* pos){
    for(int i = pos_start;i<pos_end;i++){
        if(nums[i]>=*max){
            *pos = i;
            *max = nums[*pos];
        }
    }
}

struct TreeNode* construct(int *nums,int pos_start,int pos_end){
    if(pos_start>=pos_end){
        return NULL;
    }
    int max=0,pos=0;
    get_max_num(nums,pos_start,pos_end,&max,&pos);
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = max;
    node->left = construct(nums,pos_start,pos);
    node->right = construct(nums,pos+1,pos_end);
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    struct TreeNode* root = construct(nums,0,numsSize);
    return root;
}

int main(){
    int nums[6] = {3,2,1,6,0,5};
    struct TreeNode* root = constructMaximumBinaryTree(nums,6);
    printf("%d ",root->val);
    printf("%d ",root->left->val);
    printf("%d ",root->left->right->val);
}
