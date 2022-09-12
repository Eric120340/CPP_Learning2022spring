#include <stdio.h>
#include "assign1_mat.h"
#include "assign1_mat.c"
#include "assign1.h"
int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res);
int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res);

int main() {
  int r, c;
  long long exp;
  printf("输入row,col,exp: \n");
  scanf("%d %d %lld", &r, &c, &exp);
  matrix m1 = create_matrix_all_zero(r, c);
  r *= c;
  int* m1_data = (int*) m1.m_data;
  printf("输入矩阵:\n");
  while(r--) scanf("%d", m1_data++);
  
  matrix res = create_matrix_all_zero(m1.m_row, m1.m_col);
  fast_matrix_exp(m1, exp, res);
  int* res_data = (int*) res.m_data;
  printf("\nResult\n");
  for(int r=0;r<res.m_row;++r) 
  {
   for(int c=0;c<res.m_col;++c) 
   {
     printf("%d ", *(res_data++));
    }
    printf("\n");
  }
  
  return 0;
}
//应用带入mul
int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res)
{
    long long n = exp;
    matrix mat_In = copy_matrix(mat_a);
    matrix mat_temp = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    matrix mat_out = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    matrix mat_Ide = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    matrix mat_final = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    //单位矩阵
    for (int i = 0; i < mat_a.m_row; i++)
    {
        for (int j = 0; j < mat_a.m_col; j++)
        {
            if (i == j)
                set_by_index(mat_Ide, i, j, 1);
            else
                set_by_index(mat_Ide, i, j, 0);
        }
    }
    //check size
    if (mat_In.m_row != mat_res.m_row ||
        mat_In.m_col != mat_res.m_col)
        return 1;
    //check exp
    if (n < 0){ return 1; }
    else if (n == 0)
    {
        mat_res = copy_matrix(mat_Ide);
        return 0;
    }

    else if (n == 1)
    {
        mat_res = copy_matrix(mat_a);
        return 0;
    }
    else
    {
        mat_out = copy_matrix(mat_a);
/*         for (int i = 0; i < mat_In.m_row; i++)
        {
            for (int j = 0; j < mat_In.m_row; j++)
            {
                long long temp = get_by_index(mat_a, i, j);
                set_by_index(mat_out, i, j, (int)temp);
            }
        } */
        mat_final = copy_matrix(mat_Ide);
/*         for (int i = 0; i < mat_In.m_row; i++)
        {
            for (int j = 0; j < mat_In.m_row; j++)
            {
                long long temp = get_by_index(mat_Ide, i, j);
                set_by_index(mat_final, i, j, (int)temp);
            }
        } */
        while (n != 0)
        {
            //odd number
            if (n % 2 == 1)
            {
                matrix_multiplication(mat_final, mat_out, mat_temp);
                // mat_out = copy_matrix(mat_temp);
                for (int i = 0; i < mat_In.m_row; i++)
                    for (int j = 0; j < mat_In.m_row; j++)
                    {
                        long long temp = get_by_index(mat_temp, i, j) % MODULO;
                        set_by_index(mat_final, i, j, (int)temp);
                    }
            }
            //even number
            {
                matrix_multiplication(mat_out, mat_out, mat_temp);
                for (int i = 0; i < mat_In.m_row; i++)
                    for (int j = 0; j < mat_In.m_row; j++)
                    {
                        long long temp = get_by_index(mat_temp, i, j) % MODULO;
                        set_by_index(mat_out, i, j, (int)temp);
                    }
            }
            n = n / 2;
        }
        for (int i = 0; i < mat_In.m_row; i++)
            for (int j = 0; j < mat_In.m_row; j++)
            {
                long long temp = get_by_index(mat_final, i, j);
                set_by_index(mat_res, i, j, (int)temp);
            }
        return 0;
    }
}

int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res)
{
    long long  tmp = 0;
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    //检查matRes
    //check类型 列=行
     if (mat1.m_col != mat2.m_row) 
    {
        return 1;
    }

    for(int i=0; i < mat1.m_row; i++)
    {
        for(int j=0; j < mat2.m_col; j++)
        {
            set_by_index(mat_res, i, j, 0);
            for(int k=0; k < mat1.m_col; k++)
            {
                tmp = (tmp + ((long long)get_by_index(mat1,i,k) * (long long)get_by_index(mat2,k,j)) % MODULO) % MODULO;
            }
            set_by_index(mat_res,i,j,(int)tmp);
            tmp = 0;
        }
    } 
    return 0;
}

