#include <iostream>
using namespace std;

struct PizzaInf
{
    char Com_Name[21];
    int diameter;
    float weight;
};

int main()
{
    PizzaInf pizza;
    cout << "Enter the name of pizza company: ";
    cin.get(pizza.Com_Name,20);
    cout << "Enter the diameter of pizza: ";
    cin >> pizza.diameter;
    cout << "Enter the weight of pizza: ";
    cin >> pizza.weight;
    
    cout << "Displaying the information of pizza\n";
    cout << "Company name: " << pizza.Com_Name << endl;
    cout << "Pizza diameter: " << pizza.diameter << " inches" << endl;
    cout << "Pizza weight: " << pizza.weight << " g " << endl;
}
