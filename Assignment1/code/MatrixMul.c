#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assign1_mat.h"
#include "assign1_mat.c"

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
//内存优化
int matrix_loop_multiplication(matrix mat_a, matrix mat_b, matrix mat_res)
{
    long long temp = 0;
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    //check matRes
    //check size 
     if (mat1.m_col != mat2.m_row) 
    {
        return 1;
    }
    //Mul
    for(int i=0; i < mat1.m_row; i++)
    {
        for(int k=0; k < mat2.m_row; k++)
        {
            temp = (long long)get_by_index(mat1,i,k);
            for(int j=0; j < mat2.m_col; ++j)
            {
                long long t = get_by_index(mat_res,i,j) % MODULO;
                long long p = get_by_index(mat2,k,j) % MODULO;
                set_by_index(mat_res,i,j,t + temp * p);
            }
        }
    } 
    delete_matrix(mat1);
    delete_matrix(mat2); 
    return 0;
}

int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res)
{
    long long temp = 0;
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    //check matRes
    //check size 
     if (mat1.m_col != mat2.m_row) 
    {
        return 1;
    }
    //Mul
    for(int i=0; i < mat1.m_row; i++)
    {
        for(int j=0; j < mat2.m_col; j++)
        {
            //set_by_index(mat_res, i, j, 0);
            for(int k=0; k < mat1.m_col; k++)
            {
                temp = (temp + ((long long)get_by_index(mat1,i,k) * (long long)get_by_index(mat2,k,j)) % MODULO) % MODULO;
            }
            set_by_index(mat_res,i,j,(int)temp);
            temp = 0;
        }
    }
    delete_matrix(mat1);
    delete_matrix(mat2); 
    return 0;
}

int main(void)
{
  clock_t start, finish;
  int r, c;
  printf("Input mat1 row and column:\n");
  scanf("%d %d", &r, &c);
  matrix m1 = create_matrix_all_zero(r, c);
  //set_random_matrix(m1);
    r *= c;
  int* m1_data = (int*) m1.m_data;
  printf("Input mat1\n");
  while(r--) scanf("%d", m1_data++);  

  printf("Input mat2 row and column:\n");
  scanf("%d %d", &r, &c);
  matrix m2 = create_matrix_all_zero(r, c);
  //set_random_matrix(m2);
    r *= c;
  int* m2_data = (int*) m2.m_data;
  printf("Input mat2\n");
  while(r--) scanf("%d", m2_data++);  
  
  matrix res = create_matrix_all_zero(m1.m_row, m2.m_col);

    start = clock();
    //matrix_loop_multiplication(m1,m2,res);
    matrix_multiplication(m1, m2, res);
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