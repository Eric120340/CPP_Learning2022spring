#pragma once

#include <iostream>

using namespace std;

/**
 * @brief store data in pairs
 *
 */
struct Pair {
    // TODO finish this struct
    char a;
    char b;
};

/**
 * @brief split string into pairs
 *
 * 1.一串字符串中，字符个数大于等于3个，则把两个相邻的偶数位的数放进一个pair
 * 2.字符个数大于等于4个，则把相邻的奇数位的数放在一个pair
 * 3.丢弃不成对的，一直重复
 *
 * @param s string to be splitted
 * @param length length of pairs， pairs is used to store the length of pair, (number of pairs)
 *
 * @return Pair* a pointer who points to the splitted pairs
 */
Pair* splitPair(string s, int& length);

/**
 * @brief print pair
 *
 * @param pair a pair pointer
 */
void printPair(Pair* pair);
