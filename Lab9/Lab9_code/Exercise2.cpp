#include <iostream>
#include <string>
#include <stdio.h>
#include "Exercise2.h"
using namespace SALES;
void SALES::setSales(Sales &sales, const double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        sales.sales[i] = ar[i];
    }
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (sales.sales[i] != 0)
        {
            sum += sales.sales[i];
            cnt++;
        }
    }
    sales.average = sum / cnt;
    sales.max = sales.sales[0];
    sales.min = sales.sales[0];
    for (int i = 0; i < QUARTERS; i++)
    {
        if (sales.sales[i] != 0 && sales.sales[i] > sales.max)
            sales.max = sales.sales[i];
        if (sales.sales[i] != 0 && sales.sales[i] < sales.min)
            sales.min = sales.sales[i];
    }
}

void SALES::setSales(Sales &s)
{
    double ar[QUARTERS];
    std::cout << "Enter sales for 4 quarter:";
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cin >> ar[i];
    }
    setSales(s, ar, QUARTERS);
}

void SALES::showSales(const Sales &s)
{
    std::cout << "Sales: ";
    for (int i = 0; i < QUARTERS; i++)
    {
        std::cout << s.sales[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Average: " << s.average << std::endl;
    std::cout << "Max: " << s.max << std::endl;
    std::cout << "Min: " << s.min << std::endl;
}