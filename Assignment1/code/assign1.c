#include <stdio.h>
#include <math.h>
#include "assign1_mat.h"
#include "assign1.h"

int copy_value(matrix mat_origin, matrix mat_copy);

// Part 1 Task1 20pts
// Power of x^n
int quick_power(int x, int n)
{
    unsigned long long answer = 1;
    long long x1 = x % MODULO;
    long long n1 = n;

    for (; n1 != 0; n1 /= 2)
    {
        if (n1 % 2 == 1)
        {
            answer = (answer * x1) % MODULO;
        }
        x1 = ((x1 % MODULO) * (x1 % MODULO)) % MODULO;
    }
    return answer;
}

// Task2-1 20pts
int matrix_addition(matrix mat_a, matrix mat_b, matrix mat_res)
{
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);

    // check size
    if (mat2.m_row != mat1.m_row || mat2.m_col != mat1.m_col ||
        mat2.m_row != mat_res.m_row || mat2.m_col != mat_res.m_col)
    {
        return 1;
    }
    // Addition
    for (int i = 0; i < mat_res.m_row; ++i)
    {
        for (int j = 0; j < mat_res.m_col; ++j)
        {
            long val = (((long long)get_by_index(mat1, i, j)) + ((long long)get_by_index(mat2, i, j))) % MODULO;
            set_by_index(mat_res, i, j, val);
        }
    }
    delete_matrix(mat1);
    delete_matrix(mat2);
    return 0;
}

// Tas2-2
int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res)
{
    long long temp = 0;
    matrix mat1 = copy_matrix(mat_a);
    matrix mat2 = copy_matrix(mat_b);
    // check matRes
    // check size
    if (mat1.m_col != mat2.m_row)
    {
        return 1;
    }
    if (mat1.m_row != mat_res.m_row || mat2.m_col != mat_res.m_col)
    {
        return 1;
    }

    // Mul
    for (int i = 0; i < mat1.m_row; i++)
    {
        for (int j = 0; j < mat2.m_col; j++)
        {
            set_by_index(mat_res, i, j, 0);
            for (int k = 0; k < mat1.m_col; k++)
            {
                temp = (temp + ((long long)get_by_index(mat1, i, k) * (long long)get_by_index(mat2, k, j)) % MODULO) % MODULO;
            }
            set_by_index(mat_res, i, j, (int)temp);
            temp = 0;
        }
    }
    delete_matrix(mat1);
    delete_matrix(mat2);
    return 0;
}

// Task3
int naive_matrix_exp(matrix mat_a, int exp, matrix mat_res)
{
    int i, j, times, val, q = 0;
    long long tmp = 0;
    long long temp = 0;
    matrix matIn = copy_matrix(mat_a);    // Inputs matrix Unchanged
    matrix mat_temp = copy_matrix(mat_a); // temporary matrix, after multiplied with matIn

    // check size
    if (matIn.m_row != mat_res.m_row || matIn.m_col != mat_res.m_col)
    {
        return 1;
    }
    if (exp < 0)
    {
        return 1;
    }
    // check exp
    if (exp < 0)
    {
        return 1;
    }
    // Check if exp = 0
    if (exp == 0)
    {
        for (i = 0; i <= matIn.m_row; ++i)
        {
            for (j = 0; j <= matIn.m_col; ++j)
            {
                if (i == j)
                {
                    set_by_index(mat_res, i, j, 1);
                }
                else
                {
                    set_by_index(mat_res, i, j, 0);
                }
            }
        }
        return 0;
    }

    // exp = 1
    if (exp == 1)
    {
        copy_value(matIn, mat_res);
        return 0;
    }
    // exp > 0
    for (times = 1; times < exp; times++)
    {
        // Matrix mul
        for (i = 0; i < matIn.m_row; i++)
        {
            for (int j = 0; j < matIn.m_col; j++)
            {
                set_by_index(mat_res, i, j, 0);
                for (int k = 0; k < matIn.m_col; k++)
                {
                    tmp = (tmp + (((long long)get_by_index(matIn, i, k) % MODULO) * ((long long)get_by_index(mat_temp, k, j) % MODULO)) % MODULO) % MODULO;
                }
                set_by_index(mat_res, i, j, (int)tmp);
                tmp = 0;
            }
        }
        mat_temp = copy_matrix(mat_res);
    }
    delete_matrix(matIn);
    delete_matrix(mat_temp);
    return 0;
}

// Task4
int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res)
{
    long long n = exp;
    matrix mat_In = copy_matrix(mat_a);
    matrix mat_Ide = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);

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
    // check size
    if (mat_In.m_row != mat_res.m_row ||
        mat_In.m_col != mat_res.m_col)

        return 1;
    // check exp
    if (n < 0)
    {
        delete_matrix(mat_In);
        delete_matrix(mat_Ide);
        return 1;
    }
    else if (n == 0)
    {
        mat_res = copy_matrix(mat_Ide);
        delete_matrix(mat_Ide);
        delete_matrix(mat_In);
        return 0;
    }

    else if (n == 1)
    {
        mat_res = copy_matrix(mat_a);
        delete_matrix(mat_In);
        delete_matrix(mat_Ide);
        return 0;
    }
    else
    {
        matrix mat_Buffer = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
        matrix mat_Temp = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
        matrix mat_Out = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
        mat_Temp = copy_matrix(mat_a);

        mat_Out = copy_matrix(mat_Ide);
        delete_matrix(mat_Ide);

        while (n != 0)
        {
            // odd number
            if (n % 2 == 1)
            {
                matrix_multiplication(mat_Out, mat_Temp, mat_Buffer);

                copy_value(mat_Buffer, mat_Out);
            }
            // even number
            {
                matrix_multiplication(mat_Temp, mat_Temp, mat_Buffer);

                copy_value(mat_Buffer, mat_Temp);
            }
            n = n / 2;
        }
        // Copy value
        copy_value(mat_Out, mat_res);

        delete_matrix(mat_In);
        delete_matrix(mat_Buffer);
        delete_matrix(mat_Temp);
        delete_matrix(mat_Out);
        return 0;
    }
}

// Task5
int fast_cal_fib(long long n)
{
    long long answer;
    if (n == 0)
    {
        answer = 0;
        return answer;
    }

    if (n == 1 || n == 2)
    {
        answer = 1;
        return answer;
    }
    else
    {
        matrix mat_init = create_matrix_all_zero(2, 2);
        matrix mat_mul_out = create_matrix_all_zero(2, 2);
        matrix mat_temp = create_matrix_all_zero(2, 1);
        matrix mat_Fib = create_matrix_all_zero(2, 1);
        //设置初始矩阵
        // 1 1
        // 1 0
        set_by_index(mat_init, 0, 0, 1);
        set_by_index(mat_init, 0, 1, 1);
        set_by_index(mat_init, 1, 0, 1);
        set_by_index(mat_init, 1, 1, 0);
        // 1
        // 0
        set_by_index(mat_temp, 0, 0, 1);
        set_by_index(mat_temp, 1, 0, 0);
        // fast_matrix_exp
        fast_matrix_exp(mat_init, n - 1, mat_mul_out);
        matrix_multiplication(mat_mul_out, mat_temp, mat_Fib);
        answer = (get_by_index(mat_Fib, 0, 0)) % MODULO;

        delete_matrix(mat_init);
        delete_matrix(mat_mul_out);
        delete_matrix(mat_temp);
        delete_matrix(mat_Fib);
        return answer;
    }
}

// For copy matrix value to another
int copy_value(matrix mat_origin, matrix mat_copy)
{
    for (int i = 0; i < mat_origin.m_row; i++)
    {
        for (int j = 0; j < mat_origin.m_col; j++)
        {
            long long temp = get_by_index(mat_origin, i, j);
            set_by_index(mat_copy, i, j, (int)temp);
        }
    }
    return 0;
}