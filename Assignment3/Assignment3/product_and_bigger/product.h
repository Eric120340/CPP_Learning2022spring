#pragma once
#define MODULES 10000007
/**
 * @brief return product of 2 ~ 5 int numbers   2～5个整数的乘积
 *
 * @return int product of numbers
 */
inline int product(int a, int b, int c = 1, int d = 1, int e = 1) {
    // TODO implement function
    int result;
    result = (a * b* c * d * e) % MODULES; 
    return result;
}

/**
 * @brief return product of 2 ~ 5 doubles numbers   2～5个整数的乘积
 *
 * @return double product of numbers
 */
inline double product(double a, double b, double c = 1.0, double d = 1.0, double e = 1.0) {
    // TODO implement function
    double result = a * b * c * d * e;
    return result;

}