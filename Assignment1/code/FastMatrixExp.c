#include <stdio.h>
#include "assign1_mat.h"
#include "assign1_mat.c"

int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res)
{
    matrix mat_in = copy_matrix(mat_a);
    matrix mat_temp = copy_matrix(mat_a);
    matrix mat_out;
    if (mat_res.m_row != mat_in.m_row ||
        mat_res.m_col != mat_in.m_col)
        return 1;
    if (exp < 0)
        return 1;
    if (exp == 0)
    {
        for (int i = 0; i < mat_in.m_row; i++)
            for (int j = 0; j < mat_in.m_row; j++)
            {
                if (i == j)
                    set_by_index(mat_res, i, j, 1);
                else
                    set_by_index(mat_res, i, j, 0);
            }
    }
    //exp = 1
    if (exp == 1)
    {
        for (int i = 0; i < mat_in.m_row; i++)
            for (int j = 0; j < mat_in.m_row; j++)
            {
                long long temp = get_by_index(mat_a, i, j);
                set_by_index(mat_res, i, j, (int)temp);
            }

        return 0;
    }
    else
    {
        while (exp != 0)
        {
            /* code */
        }
        
        /* unsigned long long val = 0;
        mat_out = copy_matrix(mat_in);
        for (int i = 1; i < exp; i++)
        { // doing multiplication

            if(i%2 == 1)
            {
                for (int j = 0; j < mat_in.m_row; j++)
                {
                    for (int k = 0; k < mat_in.m_col; k++)
                    {
                        for (int l = 0; l < mat_in.m_row; l++)
                        {
                            val = (val + (((long long)get_by_index(mat_in, j, l) % MODULO) * ((long long)get_by_index(mat_temp, l, k) % MODULO)) % MODULO) % MODULO;
                        }
                        set_by_index(mat_res, j, k, (int)val);
                        // printf("%d\n", (int)val);//
                        val = 0;
                    }
                }
            }
                for (int j = 0; j < mat_in.m_row; j++)
                {
                    for (int k = 0; k < mat_in.m_col; k++)
                    {
                        for (int l = 0; l < mat_in.m_row; l++)
                        {
                            val = (val + (((long long)get_by_index(mat_in, j, l) % MODULO) * ((long long)get_by_index(mat_out, l, k) % MODULO)) % MODULO) % MODULO;
                        }
                        set_by_index(mat_temp, j, k, (int)val);//%
                        // printf("%d\n", (int)val);//
                        val = 0;
                    }
                }
                mat_out = copy_matrix(mat_temp);
        }

            printf("\nmat_Out2\n");
            for(int r=0;r<mat_out.m_row;++r)
            { 
            for(int c=0;c<mat_out.m_col;++c) 
                {
                    printf("%d ", get_by_index(mat_out,r,c));
                }
                    printf("\n");
            }

            for (int i = 0; i < mat_in.m_row; i++)
            for (int j = 0; j < mat_in.m_row; j++)
            {
                long long temp = get_by_index(mat_out, i, j);
                set_by_index(mat_res, i, j, (int)temp);
            }   
 
        //delete_matrix(mat_in);
        //delete_matrix(mat_temp);
        //delete_matrix(mat_out);
        return 0;
    }
    return 0; */
}


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
//APPEND END