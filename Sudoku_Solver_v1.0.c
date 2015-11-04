/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Sudoku
 * 名称:  数独求解器
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 初始化，求解数独，并输出答案
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150725      V1.0        wuzhiyi     创建
 **************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define MAX 9
char M[MAX][MAX] = {{0}};
int count = 0;

int getblockid(int row, int col){
    return row/3 * 3 + col/3;
}
void getnext(int *row, int *col, int* nrow, int* ncol){
    if(*col ==8){
        *ncol = 0;
        *nrow = (*row)+1;
    }
    else{
        *nrow = *row;
        *ncol = (*col) +1;
    }
}
void outputmatrix(char mtr[MAX][MAX] ){
    int i, j;
    for(i=0;i<MAX;i++){
        for(j = 0; j<MAX;j++){
            printf("%d ", mtr[i][j]);
        }
        printf ( "\n" );
    }
}

void fill(int row, int col, char matrix[MAX][MAX], char rowd[][MAX], char cold[][MAX], char blod[][MAX]){
    count ++;
    if(matrix[row][col] != 0){
        if(row == 8 && col == 8){
            outputmatrix(matrix);
            return;
        }
        int nr, nc;
        getnext(&row,&col,&nr,&nc);
        fill(nr,nc,matrix,rowd,cold,blod);
        return;
    }
    int i = 1;
    char mtr[MAX][MAX];
    memcpy(mtr, matrix, MAX*MAX*sizeof(char));
    
    for(;i<= 9;i++){
        //duplicate all data
        int blockid = getblockid(row, col);
        if(
           blod[blockid][i-1]!= (char)1 &&
           rowd[row][i-1]!=(char)1 &&
           cold[col][i-1]!=(char)1
           ){
            //fill the cell
            //            printf ( "fill [%d] [ %d] with %d\n",row, col, i );
            matrix[row][col] = i;
            
            if(row == 8 && col == 8){
                outputmatrix(matrix);
                return;
            }
            //set the restriction
            blod[blockid][i-1] = 1;
            rowd[row][i-1] = 1;
            cold[col][i-1] = 1;
            int nrow,ncol;
            getnext(&row, &col, &nrow, &ncol);
            fill(nrow,ncol,matrix,rowd,cold,blod);
            //restore status
            blod[blockid][i-1] = 0;
            rowd[row][i-1] = 0;
            cold[col][i-1] = 0;
            matrix[row][col] = 0;
        }
    }
}

void trackfixedcell(char fixmtr[MAX][MAX], char r[MAX][MAX],char c[MAX][MAX],char b[MAX][MAX]){
    int row,col;
    for(row = 0; row<MAX; row++){
        for(col= 0; col<MAX; col++){
            if(fixmtr[row][col]!= 0){
                r[row][(int)fixmtr[row][col]-1] = 1;
                c[col][(int)fixmtr[row][col]-1] = 1;
                b[getblockid(row,col)][(int)fixmtr[row][col]-1] = 1;
            }
        }
    }
}
void readfixed(char mtr[MAX][MAX], char* input){
    int i = 0;
    for(;i<MAX*MAX;i++){
        int row = i/MAX;
        int col = i%MAX;
        if(input[i] != '0'){
            mtr[row][col] = input[i]-48;
        }
    }
}

int main ( int argc, char *argv[] )
{
    //输入待求解数组
    char * fixed = "045000000000000030600030807700004680000006005003000070021000456000010000480000000";
    char r[MAX][MAX] = {{0}};
    char c[MAX][MAX] = {{0}};
    char b[MAX][MAX] = {{0}};
    readfixed(M,fixed);
    trackfixedcell(M,r,c,b);
    fill(0,0,M,r,c,b);
    printf ( "count = %d\n", count );
    return EXIT_SUCCESS;
}
