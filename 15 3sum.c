#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int** threeSum(const int* nums, int numsSize, int* returnSize) {
    int i,j,k,sum=0;
    int **p = (int **)malloc(sizeof(int *)*5);

    for(i=0;i<numsSize-2;i++)
    {
        for(j=i+1;j<numsSize-1;j++)
        {
            for(k=j+1;k<numsSize;k++)
            {
                sum = nums[i]+nums[j]+nums[k];
                if (sum == 0)
                {
                    p[*returnSize] = (int*)malloc(3*sizeof(int));
                    p[*returnSize][0] = nums[i];
                    p[*returnSize][1] = nums[j];
                    p[*returnSize][2] = nums[k];
                    *returnSize += 1;
                }
            }
        }
    }
    return p;
}

int main() {
    int nums[6] = {-1,0,1,2,-1,-4};
    int *returnSize;
    int **pa,i;
    returnSize = (int *)malloc(sizeof(int));
    *returnSize = 0;
    pa = threeSum(nums,6,returnSize);
    for(i=0;i<*returnSize;i++)
    {
        printf("%d %d %d\n",pa[i][0],pa[i][1],pa[i][2]);
    }
    free(pa);
}
