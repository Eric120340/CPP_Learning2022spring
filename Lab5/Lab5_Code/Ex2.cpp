#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()

{
    cout << "Enter words (to stop,type the word done): " << endl;
    int i = 0, j = 0;
    int words = 0;
    char word[20];
    cin.get(word[i]);
    while ((int(word[i]) != int(' ')) && (int(word[i])) != int('\n'))
    {
        i++;
        cin.get(word[i]);
    }
    word[i] = '\0';
    //把在最后输入的空格或者回车去掉，否则输入的是“done+空格或换行 ”而不是“done”导致后面while条件判别错误。
    // cout << word;
    while (strcmp(word, "done"))
    {
        words++;
        int i = 0;
        cin.get(word[i]);
        //将单词之间多余的空格和回车去掉
        while ((int(word[i]) == int(' ')) || (int(word[i])) == int('\n'))
        {
            word[i] = '\0';
            cin.get(word[i]);
        }
        while ((int(word[i]) != int(' ')) && (int(word[i])) != int('\n'))
        {
            i++;
            cin.get(word[i]);
        }
        word[i] = '\0';
    }
    cout << "You entered a total of " << words << " words." << endl;

    return 0;
}
