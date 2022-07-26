/*
*’ªµƒÀ≥–Ú’ª µœ÷
*/
#include <iostream>
using namespace std;
#define MaxSize 10

typedef struct SqStack {
	int data[MaxSize];
	int top;
}SqStack;
/*
* Init a new Stack
*/
void InitStack(SqStack& s) {
	s.top = -1;
}
/*
* isEmpty?
*/
bool isEmpty(SqStack& s) {
	if (s.top == -1) {
		return true;
	}
	return false;
}
/*
* push a element into the stack
*/
bool Push(SqStack& s, int x) {
	if (s.top == MaxSize - 1) {
		return false;
	}
	s.data[++s.top] = x;
	return true;
}
/*
* pop a element from the stack
*/

bool Pop(SqStack& s, int& x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top--];
	return true;
}
/*
* getTop,get the top elemnt without pop it
*/
bool GetTop(SqStack& s, int& x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top];
	return true;
}

void Print(SqStack s) {
	for (int i = 0;i <= s.top;i++) {
		cout << s.data[i] << " ";
	}
	cout << endl;
}
int main() {
	SqStack s;
	InitStack(s);

	Push(s, 5);
	Push(s, 123);
	Push(s, 345);
	Push(s, 45);
	Push(s, 1);

	Print(s);
	int x;
	Pop(s, x);
	Print(s);
	Pop(s, x);
	Print(s);
	Pop(s, x);
	Print(s);
	Pop(s, x);
	Print(s);
	Pop(s, x);
	Print(s);
	Pop(s, x);Pop(s, x);Pop(s, x);
	return 0;
}