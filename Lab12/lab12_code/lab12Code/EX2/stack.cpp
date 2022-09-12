#include "stack.h"
#include <iostream>
using namespace std;
Stack::Stack (int n)
{
	size = n;
	top = 0;
	pitems = new Item[n];
}
Stack::Stack (const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for(int i = 0; i < size; i++)
		pitems[i] = st.pitems[i];
}
Stack::~Stack()
{
	delete[] pitems;
}
bool Stack::isempty() const
{
	return top == 0;
}
bool Stack::isfull() const
{
	return top == size;
}
bool Stack::push(const Item & item)
{
	if(top == size) return 0;
	pitems[++top] = item;
	return 1;
}
bool Stack::pop(Item & item)
{
	if(top == 0) return 0;
	item = pitems[top--];
	return 1;
}
Stack & Stack::operator = (const Stack & st)
{
	if(this == &st) return *this;
	size = st.size;
	top = st.top;
	delete[] pitems;
	pitems = new Item[size];
	for(int i = 0; i < size; i++)
		pitems[i] = st.pitems[i];
	return *this;
}