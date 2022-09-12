#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include "assign1_mat.h"
#include "assign1_mat.c"


//矩阵加法
int matrix_addition(matrix mat_a, matrix mat_b, matrix mat_res)
{
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    

     if (mat2.m_row != mat1.m_row ||
        mat2.m_col != mat1.m_col || 
        mat2.m_row != mat_res.m_row || 
        mat2.m_col != mat_res.m_col) {
        return 1;
    }
    
    for(int i=0; i< mat_res.m_row; ++i){
        for(int j=0; j < mat_res.m_col; ++j){
            long val = (((long long) get_by_index(mat1, i, j)) + ((long long) get_by_index(mat2, i, j))) % MODULO;
            set_by_index(mat_res, i, j, val);
        }
    }
    return 0;
}

//APPEND BEGIN
//APPEND BEGIN
int main(void) {
  int r, c;
  scanf("%d %d", &r, &c);
  matrix m1 = create_matrix_all_zero(r, c);
  r *= c;
  int* m1_data = (int*) m1.m_data;
  while(r--) scanf("%d", m1_data++);
  
  scanf("%d %d", &r, &c);
  matrix m2 = create_matrix_all_zero(r, c);
  r *= c;
  int* m2_data = (int*) m2.m_data;
  while(r--) scanf("%d", m2_data++);
  
  matrix res = create_matrix_all_zero(m1.m_row, m2.m_col);
  matrix_addition(m1, m2, res);
  int* res_data = (int*) res.m_data;
  
  for(int r=0;r<res.m_row;++r) {
  	for(int c=0;c<res.m_col;++c) {
    	printf("%d ", *(res_data++));
    }
    printf("\n");
  }
  
  return 0;
}