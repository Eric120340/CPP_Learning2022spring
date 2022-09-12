#include <stdio.h>
#include "assign1_mat.h"
#include "assign1_mat.c"
int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res);
int fast_cal_fib(long long n);
int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res);

int main()
{

    long long number;
    printf("\nnumber\n");
    scanf("%lld",&number);
    printf("%lld",fast_cal_fib(number));
    return 0;
}

int fast_cal_fib(long long n)
{
    long long answer;
    matrix mat_init = create_matrix_all_zero(2,2);
    matrix mat_mul_out = create_matrix_all_zero(2,2);
    matrix mat_temp = create_matrix_all_zero(2,1);
    matrix mat_Fib = create_matrix_all_zero(2,1);
     //设置初始矩阵
    // 1 1
    // 1 0
    set_by_index(mat_init,0,0,1);
    set_by_index(mat_init,0,1,1);
    set_by_index(mat_init,1,0,1);
    set_by_index(mat_init,1,1,0);
    // 1
    // 0
    set_by_index(mat_temp,0,0,1);
    set_by_index(mat_temp,1,0,0);

    if(n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
     else
    {
    //递归  
    fast_matrix_exp(mat_init,n-1,mat_mul_out);
    matrix_multiplication(mat_mul_out,mat_temp,mat_Fib);
    answer = (get_by_index(mat_Fib,0,0)) % MODULO;
    return answer;
    } 
}

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



