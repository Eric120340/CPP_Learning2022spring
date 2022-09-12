#include <stdio.h>
#include "assign1_mat.h"
#include "assign1.h"
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
    if (mat_res.m_row != mat_a.m_row ||
        mat_res.m_col != mat_a.m_col)
        return 1;
    if (exp < 0)
        return 1;
    else if (exp == 0)
    {
        for (int i = 0; i < mat_a.m_row; i++)
            for (int j = 0; j < mat_a.m_row; j++)
            {
                if (i == j)
                    set_by_index(mat_res, i, j, 1);

                else
                    set_by_index(mat_res, i, j, 0);
            }
    }

    else if (exp == 1)
    {
        mat_res = copy_matrix(mat_a);
        return 0;
    }
    else
    {
        matrix mat_x = copy_matrix(mat_a);
        matrix mat_y = copy_matrix(mat_a);
        matrix mat_z;
        long long val = 0;
        for (int i = 0; i < exp; i++)
        {
            for (int j = 0; j < mat_a.m_row; j++)
            {
                for (int k = 0; k < mat_a.m_col; k++)
                {
                    for (int l = 0; l < mat_a.m_row; l++)
                    {
                        val = val + (((long long)get_by_index(mat_x, i, k)) * ((long long)get_by_index(mat_y, k, j))) % MODULO;
                    }
                    set_by_index(mat_z, i, j, (int)val);
                    val = 0;
                }
            }
            // matrix_multiplication(mat_x, mat_y, mat_z);
            mat_y = copy_matrix(mat_z);
        }
        mat_res = copy_matrix(mat_y);
        delete_matrix(mat_x);
        delete_matrix(mat_y);
        delete_matrix(mat_z);
        return 0;
    }
}

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