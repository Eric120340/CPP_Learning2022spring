#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#define VN 5
#define CN 21
using namespace std;

const char vowel[VN] = {'a','e','i','o','u'};
const char consonants[CN] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
int main()
{
    int numV = 0, numC = 0, numE = 0;
    char word[40];
    cout << "Enter words (q to quit):" << endl;

    while(cin >> word)
    {
        if (isalpha(word[0]))
        {
            if (strlen(word) == 1 && word[0] == 'q')
            {
                break;
            }
            char x = tolower(word[0]);

            for (int i = 0; i < VN; i++)
            {
                if (x == vowel[i])
                {
                    numV++;
                }
            }
            for (int i = 0; i < CN; i++)
            {
                if (x == consonants[i])
                {
                    numC++;
                }
            }
        }
        else
            numE++;
        
    }
    cout << numV << " words beginning with vowels" << endl;
    cout << numC << " words beginning with consonants" << endl;
    cout << numE << " others" << endl;

}