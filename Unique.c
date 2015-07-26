/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  SS_Unique.c
 * 名称:  唯一解函数
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 分别判断行，列，宫中是否存在唯一一个未知数
 *           确定该未知数的值并赋值
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150726       V3.0         wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

#define N 9
//查找行中是否存在 k
int Exist_Row(int a[N][N], int i, int k) {
    int j, result = 0;
    for (j=0; j<N; j++) {
        if (a[i][j] == k) result = 1;
    }
    return result;
}

//查找列中是否存在 k
int Exist_Col(int a[N][N], int j, int k) {
    int i, result = 0;
    for (i=0; i<N; i++) {
        if (a[i][j] == k) result = 1;
    }
    return result;
}

//查找宫中是否存在 k
int Exist_Blk(int a[N][N], int i, int j, int k) {
    int x=i/3, y=j/3;   //x 与 y 表示宫格坐标
    //printf ("查找宫(%d,%d)中是否存在 %d\n", x, y, k);
    int result = 0;
    for (int m=0; m<3; m++){
        for (int n=0; n<3; n++) {
            if (a[3*x+m][3*y+n] == k) {
                //printf ("\t发现 a[%d][%d]=%d\n", 3*x+m, 3*y+n, k);
                result = 1;}
        }
    }
    return result;
}

//唯一解函数：行
void Unique_Row(int a[N][N], int i) {
    int k, j;
    int count = 0, flag = N+1;
    for (j=0; j<N; j++) {   //每行逐个判断
        if (a[i][j] == 0) {
            count += 1;     //记录一行中0的个数
            flag = j;       //记录唯一解的位置
        }
    }
    if (count == 1) {       //一行中只有一个0，即为唯一解
        printf ("Row unique is a[%d][%d]\n", i, flag);
        //找到唯一解的值，并赋值
        for (k=1; k<N+1; k++) {
            if (Exist_Row(a, i, k) != 1) {
                a[i][flag] = k;
                printf ("a[%d][%d]=%d\n", i, flag, k);
            }
        }
    }
}

//唯一解函数：列
void Unique_Col(int a[N][N], int j) {
    int k, i;
    int count = 0, flag = N+1;
    for (i=0; i<N; i++) {   //每列逐个判断
        if (a[i][j] == 0) {
            count += 1;     //记录一列中0的个数
            flag = i;       //记录唯一解的位置
        }
    }
    if (count == 1) {       //一列中只有一个0，即为唯一解
        printf ("Column unique is a[%d][%d]\n", flag, j);
        //找到唯一解的值，并赋值
        for (k=1; k<N+1; k++) {
            if (Exist_Col(a, j, k) != 1) {
                a[flag][j] = k;
                printf ("a[%d][%d]=%d\n", flag, j, k);
            }
        }
    }
}

//唯一解函数：宫
void Unique_Blk(int a[N][N], int i, int j) {
    int x=i/3, y=j/3;   //x 与 y 表示宫格坐标
    int k; //唯一解的值
    int count = 0, flag_m = N+1, flag_n = N+1;
    //宫内循环查找是否有唯一解，若有，记录下唯一解位置
    for (int m=0; m<3; m++){
        for (int n=0; n<3; n++) {
            if (a[3*x+m][3*y+n] == 0) {
                count += 1;
                flag_m = m;
                flag_n = n;
            }
        }
    }
    if (count == 1) {   //宫内只有一个0，即为唯一解
        printf ("block count = %d\n", count);
        printf ("Block unique is a[%d][%d]\n", flag_m, flag_n);
        //找到唯一解的值，并赋值
        for (k=1; k<N+1; k++) {
            if (Exist_Blk(a, i, j, k) != 1) {
                a[flag_m][flag_n] = k;
                printf ("a[%d][%d]=%d\n", flag_m, flag_n, k);
            }
        }
    }
}

//唯一解函数
void Unique(int a[N][N]) {
    int i, j;
    //临时数组初始化
    int temp[N][N];
    //数组拷贝
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) temp[i][j] = a[i][j];
    }
    //行列循环查找，一旦找到唯一解，重新查找
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            Unique_Row(temp, i);
            Unique_Col(temp, j);
            Unique_Blk(temp, i, j);
        }
    }
    //打印数组
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf ("%d ", temp[i][j]);
            if ((j+1)%3 == 0) printf (" ");
            if ((j+1)%9 == 0) printf ("\n");
        }
        if ((i+1)%3 == 0) printf ("\n");
    }
}

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

//主函数
int main() {
    //初始化
    int arr[N][N] = {7,5,3, 0,1,8, 0,2,0,
                     6,0,8, 0,2,7, 0,3,1,
                     2,1,0, 0,0,0, 0,8,0,
        
                     4,0,7, 0,0,0, 1,0,2,
                     1,0,2, 7,0,0, 0,0,0,
                     3,0,5, 1,0,2, 0,0,0,
        
                     5,3,6, 2,9,1, 0,0,0,
                     9,2,4, 8,7,5, 3,1,6,
                     0,7,1, 3,6,4, 2,5,0,};
    printf ("原始数组：\n");
    Print(arr);
    printf ("实验结果：\n");
    Unique(arr);
}
