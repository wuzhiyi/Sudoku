/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Sudoku
 * 名称:  数独解法
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 解数独
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150725       V1.0         wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

#define N 9

//打印函数
void Print(int a[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf ("%d ", a[i][j]);
            if ((j+1)%3 == 0) printf (" ");
            if ((j+1)%9 == 0) printf ("\n");
        }
        if ((i+1)%3 == 0) printf ("\n");
    }
}

//判断第 i 行, 第 j 列的数设为 k 是否合理
int Check(int a[N][N], int i, int j, int k) {
    int m, n;
    //Row
    for (n=0; n<N; n++) {
        if (a[i][n] == k) return 0;
    }
    //Column
    for (m=0; m<N; m++) {
        if (a[m][j] == k) return 0;
    }
    //Block
    int b1 = (i/3)*3, b2 = (j/3)*3;
    for (m=b1; m<b1+3; m++) {
        for (n=b2; n<b2+3; n++) {
            if (a[m][n] == k) return 0;
        }
    }
    //Valid
    return 1;
}

//数独求解函数
void Sudoku(int a[N][N], int n){
    int temp[N][N];
    int i,j;
    for (i=0; i<9; i++) {
        for (j=0; j<9; j++) temp[i][j] = a[i][j];
    }
    i = n/N; j = n%N;   //求出第 n 个数的行数和列数
    if (a[i][j] != 0) { //已经有原始数据
        if (n == 80) Print(temp);   //数组最后一位，输出
        else Sudoku(temp, n+1);     //不是数组最后一位，求下一个数
    }
    else {  //没有原始数据
        for (int k=1; k<=9; k++) {
            int flag = Check(temp, i, j, k);
            if (flag) {         //第 i 行, 第 j 列可以是 k
                temp[i][j] = k; //设为 k
                if (n == 80) Print(temp);
                else Sudoku(temp, n+1);
                temp[i][j] = 0; //恢复为0，判断下一个k
            }
        }
    }
}

int main() {
    //初始化
    int arr[N][N] = {6,0,0, 0,8,7, 0,0,0,
                     0,0,0, 9,0,5, 7,0,6,
                     0,4,0, 0,0,0, 0,8,0,
        
                     0,3,0, 0,0,2, 0,0,0,
                     0,0,4, 0,0,0, 6,9,0,
                     0,0,0, 4,1,0, 0,2,3,
        
                     5,0,0, 0,3,0, 1,7,0,
                     0,8,0, 0,9,0, 2,0,0,
                     0,0,1, 0,7,6, 3,0,0,};
    Print(arr);
    Sudoku(arr, 0);
}
