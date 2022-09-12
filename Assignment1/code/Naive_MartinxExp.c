#include <stdio.h>
#include "assign1_mat.h"
#include "assign1_mat.c"

int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res)
{
    long long  tmp = 0;
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    //检查matRes
    //check类型 列=行
     if (mat1.m_col != mat2.m_row) {
        return 1;
    }

    for(int i=0; i < mat1.m_row; i++){
        for(int j=0; j < mat2.m_col; j++){
            set_by_index(mat_res, i, j, 0);
            for(int k=0; k < mat1.m_col; k++){
                tmp = tmp + ((long long)get_by_index(mat1,i,k) * (long long)get_by_index(mat2,k,j)) % MODULO;
            }
            set_by_index(mat_res,i,j,(int)tmp);
            tmp = 0;
        }
    } 

    return 0;
}

int naive_matrix_exp(matrix mat_a, int exp, matrix mat_res)
{
    int i,j,times,val,q=0;
    long long tmp = 0;
    long long temp = 0;
    matrix matIn = copy_matrix(mat_a);      //Inputs matrix Unchanged
    matrix mat_tmp = copy_matrix(mat_a); //temporary matrix, after multiplied with matIn

    //mat_res = create_matrix_all_zero(mat_a.m_row, mat_a.m_col); //Output matrix
    //check size
    if(matIn.m_row != mat_res.m_row || matIn.m_col != mat_res.m_col)
    {
        return 1;
    }
    if(exp<0)
    {
        return 1;
    }

    //Check if exp = 0
    if(exp == 0)
    {
        for(i=0; i<=matIn.m_row; ++i)
        {
            for(j=0; j<=matIn.m_col; ++j)
            {
                if(i==j)
                {
                    set_by_index(mat_res,i,j,1);
                }else{
                    set_by_index(mat_res,i,j,0);
                }
            }
        }
        return 0; 
    }

    //一次幂
    if(exp==1)
    {
        for(int i=0; i<matIn.m_row; i++)
        {
            for(int j=0; j<matIn.m_col; j++)
            {
                tmp = get_by_index(matIn,i,j);
                set_by_index(mat_res,i,j,tmp);
            }
            tmp = 0;
        }
        return 0;
    }
    
    //乘法
    for(times=1; times<exp; times++)        //指数乘的次数
    {
        //printf("times: %d\n",times);
        //矩阵乘法
         for(i=0; i < matIn.m_row; i++){
        for(int j=0; j < matIn.m_col; j++){
            set_by_index(mat_res, i, j, 0);
            for(int k=0; k < matIn.m_col; k++){
                tmp = (tmp + (((long long)get_by_index(matIn,i,k) % MODULO) * ((long long)get_by_index(mat_tmp,k,j)%MODULO)) % MODULO) % MODULO;
            }
            set_by_index(mat_res,i,j,(int)tmp);
            tmp = 0;
        }
        
        } 

        //每次矩阵相乘之后，将
        for (int i = 0; i <= matIn.m_row; i++)
        {
            for(int j = 0; j <=matIn.m_col;j++)
            {
                temp = (unsigned long long)get_by_index(mat_res,i,j) % MODULO;
                set_by_index(mat_tmp,i,j,(int)temp);     //矩阵b等于矩阵c
            }
        }
        //Check
/*         printf("\nmat_tmp2\n");
        for(int r=0;r<mat_res.m_row;++r) 
        {   
            for(int c=0;c<mat_res.m_col;++c) 
            {
                printf("%d ", get_by_index(mat_tmp,r,c));
            }
            printf("\n");
        } */
    }
    return 0;
} 


    /* long long  tmp = 0;
    matrix matIn = copy_matrix(mat_a);
    matrix matExp = copy_matrix(mat_a);
    //mat_res = create_matrix_all_zero(mat_res.m_row, mat_res.m_col);

    //检查matRes
    //check类型 列=行
    if (matIn.m_row == matExp.m_row || mat_a.m_col == matExp.m_col) {
        return 1;
    }

for(;exp != 0; exp--){
    
    for(int i=0; i < matIn.m_row; i++){
        for(int j=0; j < matIn.m_col; j++){
            for(int k=0; k < matIn.m_col; k++){
                tmp = tmp + ((long long)get_by_index(matIn,i,k) * (long long)get_by_index(matExp,k,j)) % MODULO;
            }
            set_by_index(mat_res,i,j,(int)tmp);
            tmp = 0;
        }
    }
    matIn = copy_matrix(mat_res);

}

    return 0; */










int main(void)
{
  int r, c;
  long long exp;
  printf("输入 行 列,exp: \n");
  scanf("%d %d %lld", &r, &c, &exp);
  matrix m1 = create_matrix_all_zero(r, c);
  r *= c;
  int* m1_data = (int*) m1.m_data;
  printf("输入矩阵: \n");
  while(r--) scanf("%d", m1_data++);
  
  matrix res = create_matrix_all_zero(m1.m_row, m1.m_col);
  naive_matrix_exp(m1, exp, res);

  int* res_data = (int*) res.m_data;
  
  printf("\nResult\n");
  for(int r=0;r<res.m_row;++r) {
   for(int c=0;c<res.m_col;++c) {
     printf("%d ", *(res_data++));
    }
    printf("\n");
  }
  
  return 0;
}

