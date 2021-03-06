#include <stdio.h>
#include <malloc.h>

int** flipAndInvertImage(int** A, int ARowSize,const int *AColSizes, int** columnSizes, int* returnSize) {
/**
 * 注意函数中五个形参的作用：
 * 二维指针A是为了将二维数组带入函数（注意带入的方法）；
 * ARowSize是指明二位数组的行数；
 * 数组AColSizes指明了函数每一行的列数；
 * 二维指针columnSizes是将函数内定义的一个包含每行列数的数组带出函数，所以是一个二维指针；
 * 指针returnSize表示返回的二维数组的行数。
 */
    int i,j,**p;
    *returnSize = ARowSize;
    p = (int **)malloc(ARowSize*sizeof(int *));/*
 * 在函数中使用指针创建二维数组，需要一个二级指针和一个指针数组*/
    *columnSizes = (int*)malloc(sizeof(int)*ARowSize);
    for(i=0;i<ARowSize;i++) {

        (*columnSizes)[i] = AColSizes[i];

        p[i] = (int *)malloc(AColSizes[i]*sizeof(int));

        for(j=0;j<(AColSizes[i]+1)/2;j++) {
            p[i][j] = A[i][AColSizes[i]-1-j]^1;
            p[i][AColSizes[i]-1-j] = A[i][j]^1;
        }
    }
    return p;
}

int main()
{
	int A[3][3]={{1,1,0},{1,0,1},{0,0,0}},ARowSize=3,AColSizes[3]={3,3,3},**columnSizes,*returnSize,*p[3];

	p[0]=A[0];  /*C语言中若函数的形参为二维指针，实参不能直接用二维数组的数组名，需要将二维数组构造成指针数组*/
	p[1]=A[1];
	p[2]=A[2];
	int **q = p;

    columnSizes = (int**)malloc(sizeof(int*));/*指针作为实参前应该有实际的内存空间，这是因为指针在定义时不会自动为其分配内存空间*/
	returnSize = (int *)malloc(sizeof(int));

	int **C = flipAndInvertImage(q,ARowSize,AColSizes,columnSizes,returnSize);

    for(int i=0;i<*returnSize;i++) {
        for(int j=0;j<(*columnSizes)[i];j++) {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }

	free(C);
    free(columnSizes);
	free(returnSize);
	return 0;
}
