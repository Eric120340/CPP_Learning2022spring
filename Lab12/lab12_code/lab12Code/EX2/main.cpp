#include <iostream>
#include "stack.h"
using namespace std;
int main(){
	Stack a, b = Stack(2);
	b.push(3);
	b.push(4);
	cout << b.isfull() << endl;
	a.push(1);
	a.push(2);
	b = a;
	cout << b.isfull() << endl;
	Item pop;
	a.pop(pop);
	cout << pop << endl;
	a.pop(pop);
	cout << pop << endl;
	cout << a.isempty() << endl;
}
