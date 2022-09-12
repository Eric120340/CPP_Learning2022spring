#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "How many classes did you take in last semester?";
    cin >> n;

    float *pScore = new float[n];
    float *pt = pScore;

    cout << "Input " << n << " Scores: ";
    for (; pt < pScore + n; pt++)
    {
        cin >> *pt;
    }
    
    cout << "The scores are :\n";
    pt = pt - n;

    for(; pt < pScore + n; pt++)
    {
        cout << *pt << "\t";
    }
    cout << "\n";

    delete []pScore;

    return 0;
    
}