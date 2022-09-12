#include <stdio.h>
#include <time.h>
#include "assign1_mat.h"
#include "assign1_mat.c"
int Copy_value(matrix matIn, matrix matCopy);
void sub_matrix(matrix Mat, matrix Sub, int row, int col, int row_sub, int col_sub);
int strassen_launch(matrix mat_a, matrix mat_b, matrix mat_res);
int matrix_addition(matrix mat_a, matrix mat_b, matrix mat_res);
int matrix_subtraction(matrix mat_a, matrix mat_b, matrix mat_res);
int strassen(matrix mat_a, matrix mat_b, matrix mat_res);
int Sum(matrix C11, matrix C12, matrix C21, matrix C22, matrix res);

int set_random_matrix(matrix mat)
{

for(int r=0;r<mat.m_row;++r) 
{
  	for(int c=0;c<mat.m_col;++c) 
    {
    	set_by_index(mat,r,c,rand());
    }
}
  return 0;
}

int main(void)
{
  clock_t start, finish;
  int r, c;
  printf("Input mat1 row and column:\n");
  scanf("%d %d", &r, &c);
  matrix m1 = create_matrix_all_zero(r, c);
    set_random_matrix(m1);
   /* r *= c;
  int* m1_data = (int*) m1.m_data;
  printf("Input mat1\n");
  while(r--) scanf("%d", m1_data++); 
 */
  printf("Input mat2 row and column:\n");
  scanf("%d %d", &r, &c);
  matrix m2 = create_matrix_all_zero(r, c);
    set_random_matrix(m2);
  /*  r *= c;
  int* m2_data = (int*) m2.m_data;
  printf("Input mat2\n");
  while(r--) scanf("%d", m2_data++);  */
  
  matrix res = create_matrix_all_zero(m1.m_row, m2.m_col);

    start = clock();
    strassen_launch(m1,m2,res);
    //matrix_multiplication(m1, m2, res);
    finish = clock();

  int* res_data = (int*) res.m_data;
  
/*    printf("Result\n");
  for(int r=0;r<res.m_row;++r) {
  	for(int c=0;c<res.m_col;++c) {
    	printf("%d ", *(res_data++));
    }
    printf("\n");
  }  */
      printf("time: %f\n",(double)(finish - start) / CLOCKS_PER_SEC);
  
  return 0;
}

int strassen_launch(matrix mat_a, matrix mat_b, matrix mat_res)
{
    //方阵检查
    if(mat_a.m_row != mat_a.m_col || mat_b.m_row != mat_b.m_col)
    {
        printf("Must be square matrix!\n");
        return 1;
    }
    if (mat_a.m_row != mat_b.m_col)
    {
        printf("A and B must be same size!\n");
        return 1;
    }
    
    int n = mat_a.m_row;
     if(n & (n-1))   //check if n is 2^x
    {
        printf("Must be power of 2!\n");
        return 1;
    } 
    //Normal
    strassen(mat_a,mat_b,mat_res);
    return 0;
}

int strassen(matrix mat_a, matrix mat_b, matrix mat_res)
{
    int n = mat_a.m_row;
    n /= 2;

    matrix A11, A12, A21, A22, B11, B12, B21, B22;
    //A11
    matrix sub1 =create_matrix_all_zero(n,n);
    sub_matrix(mat_a,sub1,0,0,n,n);
    Copy_value(sub1,A11);
    delete_matrix(sub1);
    //A12
    matrix sub2 =create_matrix_all_zero(n,n);
    sub_matrix(mat_a,sub2,0,n,n,n);
    Copy_value(sub2,A12);
    delete_matrix(sub2);
    //A21
    matrix sub3 =create_matrix_all_zero(n,n);
    sub_matrix(mat_a,sub3,n,0,n,n);
    Copy_value(sub3,A21);
    delete_matrix(sub3);
    //A22
    matrix sub4 =create_matrix_all_zero(n,n);
    sub_matrix(mat_a,sub4,n,n,n,n);
    Copy_value(sub4,A22);
    delete_matrix(sub4);
    //B11
    matrix sub5 =create_matrix_all_zero(n,n);
    sub_matrix(mat_b,sub5,0,0,n,n);
    Copy_value(sub5,B11);
    delete_matrix(sub5);
    //B12
    matrix sub6 =create_matrix_all_zero(n,n);
    sub_matrix(mat_b,sub6,0,n,n,n);
    Copy_value(sub6,B12);
    delete_matrix(sub6);
    //B21
    matrix sub7 =create_matrix_all_zero(n,n);
    sub_matrix(mat_b,sub7,n,0,n,n);
    Copy_value(sub7,B21);
    delete_matrix(sub7);
    //B22
    matrix sub8 =create_matrix_all_zero(n,n);
    sub_matrix(mat_b,sub8,n,n,n,n);
    Copy_value(sub8,B22);
    delete_matrix(sub8);

    matrix S1,S2,S3,S4,S5,S6,S7,S8,S9,S10;
    matrix_subtraction(B12,B22,S1);
    matrix_addition(A11,A12,S2);
    matrix_addition(A21,A22,S3);
    matrix_subtraction(B21,B11,S4);
    matrix_addition(A11,A22,S5);
    matrix_addition(B11,B22,S6);
    matrix_subtraction(A12,A22,S7);
    matrix_addition(B21,B22,S8);
    matrix_subtraction(A11,A22,S9);
    matrix_addition(B11,B22,S10);

    matrix F1,F2,F3,F4,F5,F6,F7;
    strassen(A11,S1,F1);
    strassen(S2,B22,F2);
    strassen(S3,B11,F3);
    strassen(A22,S4,F4);
    strassen(S5,S6,F5);
    strassen(S7,S8,F6);
    strassen(S9,S10,F7);
    
    matrix C11,C12,C21,C22;
    matrix_addition(F5,F4,C11);
    matrix_subtraction(C11,F2,C11);
    matrix_addition(C11,F6,C11);

    matrix_addition(F1,F2,C12);
    matrix_addition(F3,F4,C21);
    
    matrix_addition(F5,F1,C22);
    matrix_subtraction(C22,F3,C22);
    matrix_subtraction(C22,F7,C22);

    Sum(C11,C12,C21,C22,mat_res);
    delete_matrix(A11);
    delete_matrix(A12);
    delete_matrix(A21);
    delete_matrix(A22);
    delete_matrix(B11);
    delete_matrix(B12);
    delete_matrix(B21);
    delete_matrix(B22);
    delete_matrix(S1);
    delete_matrix(S2);
    delete_matrix(S3);
    delete_matrix(S4);
    delete_matrix(S5);
    delete_matrix(S6);
    delete_matrix(S7);
    delete_matrix(S8);
    delete_matrix(S9);
    delete_matrix(S10);
    delete_matrix(F1);
    delete_matrix(F2);
    delete_matrix(F3);
    delete_matrix(F4);
    delete_matrix(F5);
    delete_matrix(F6);
    delete_matrix(F7);
    return 0;
}

void sub_matrix(matrix Mat, matrix Sub, int row, int col, int row_sub, int col_sub)
{
    long long temp = 0;
    for (int i = 0; i < row_sub; ++i)
    {
        for (int j = 0; j < col_sub; ++j)
        {
            temp = get_by_index(Mat,i+row,j+col);
            set_by_index(Sub,i,j,temp);
        }
    }
}

int Sum(matrix C11, matrix C12, matrix C21, matrix C22, matrix res)
{
    long long temp1, temp2, temp3, temp4;
    temp1=  temp2 =  temp3 =  temp4 = 0;
    matrix sum = create_matrix_all_zero(C11.m_row * 2, C11.m_col * 2);
    for (int i = 0; i < C11.m_row; ++i)
    {
        for (int j = 0; j < C11.m_col; ++j)
        {
            temp1 = get_by_index(C11,i,j);
            temp2 = get_by_index(C12,i,j);
            temp3 = get_by_index(C21,i,j);
            temp4 = get_by_index(C22,i,j);

            set_by_index(sum,i,j,temp1);
            set_by_index(sum,i,(j + C11.m_col),temp2);
            set_by_index(sum,(i + C11.m_row),j,temp3);
            set_by_index(sum,(i + C11.m_row),(j + C11.m_col),temp4);
        }
    }
    Copy_value(sum,res);
    delete_matrix(sum);
    return 0;
}

int matrix_addition(matrix mat_a, matrix mat_b, matrix mat_res)
{
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    
    //check size
     if (mat2.m_row != mat1.m_row || mat2.m_col != mat1.m_col || 
        mat2.m_row != mat_res.m_row || mat2.m_col != mat_res.m_col) 
    {
        return 1;
    }
    //Addition
    for(int i=0; i< mat_res.m_row; ++i)
    {
        for(int j=0; j < mat_res.m_col; ++j)
        {
            long val = (((long long) get_by_index(mat1, i, j)) + ((long long) get_by_index(mat2, i, j))) % MODULO;
            set_by_index(mat_res, i, j, val);
        }
    }
    delete_matrix(mat1);
    delete_matrix(mat2);
    return 0;
}

int matrix_subtraction(matrix mat_a, matrix mat_b, matrix mat_res)
{
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    
    //check size
     if (mat2.m_row != mat1.m_row || mat2.m_col != mat1.m_col || 
        mat2.m_row != mat_res.m_row || mat2.m_col != mat_res.m_col) 
    {
        return 1;
    }
    //Addition
    for(int i=0; i< mat_res.m_row; ++i)
    {
        for(int j=0; j < mat_res.m_col; ++j)
        {
            long val = (((long long) get_by_index(mat1, i, j)) - ((long long) get_by_index(mat2, i, j))) % MODULO;
            set_by_index(mat_res, i, j, val);
        }
    }
    delete_matrix(mat1);
    delete_matrix(mat2);
    return 0;
}

int Copy_value(matrix matIn, matrix matCopy)
{
    for (int i = 0; i < matIn.m_row; i++)
    {
        for (int j = 0; j < matIn.m_row; j++)
        {
            long long temp = get_by_index(matIn, i, j);
            set_by_index(matCopy, i, j, (int)temp);
        }
    }
    return 0;
}