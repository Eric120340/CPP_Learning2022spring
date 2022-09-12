#include <iostream>

#include "bigger.h"

using namespace std;


int main() {
     // test int
    cout << "=== test int ===" << endl;
    cout << bigger(1, 2) << endl;

    // test double
    cout << "=== test double ===" << endl;
    cout << bigger(1.5, 2.5) << endl;

    // test const char * (type of "a" is const char *)
    cout << "=== test const char* ===" << endl;
    cout << bigger("The course we take is very hard", "It's true, I already knew this before i sign in") << endl;
    
    // test string
    cout << "=== test string ===" << endl;
    string s1 = "The course we take is very hard";
    string s2 = "ab";
/*     cout << s1 << endl;
    cout << s2.compare(s1) << endl;
    cout << s1.compare(s2) << endl; */
    cout << bigger(s1, s2) << endl; 

    return 0;
}