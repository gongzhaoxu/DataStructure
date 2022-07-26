/*
*栈的链式栈实现,不带头结点
*/
#include <iostream>
using namespace std;

typedef struct Linknode {
	char data;
	struct Linknode* next;
}Linknode, * LiStack;
/*
* Init a new Stack
*/
void InitStack(LiStack& s) {
	s = NULL;
}
/*
* isEmpty?
*/
bool isEmpty(LiStack& s) {
	if (s == NULL) {
		return true;
	}
	return false;
}

/*
* push a element into the stack
*/
bool Push(LiStack& s, char x) {
	Linknode* p = (Linknode*)malloc(sizeof(Linknode));
	p->data = x;
	p->next = s;//头插
	s = p;//改变栈头
	return true;
}
/*
* pop a element from the stack
*/

bool pop(LiStack& s, char& x) {
	if (isEmpty(s)) {
		return false;
	}
	Linknode* p = s;
	x = p->data;
	s = s->next;
	free(p);
	return true;
}
/*
* getTop,get the top elemnt without pop it
*/
bool GetTop(LiStack& s, char& x) {
	if (s->next == NULL) {
		return false;
	}
	x = s->data;
	return true;
}

void Print(LiStack s) {
	while (s) {
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}
/*
* 括号匹配算法
*/
bool BracketMatch(const char* str, int length) {
	LiStack s;
	InitStack(s);
	for (int i = 0;i < length;i++) {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {//左括号压栈
			Push(s, str[i]);
		}
		else {
			if (isEmpty(s)) {//若此时栈已空，则右括号单身
				return false;
			}
			char x;
			pop(s, x);
			//若左右括号不匹配
			if (x == '{' && str[i] != '}') {
				return false;
			}
			if (x == '[' && str[i] != ']') {
				return false;
			}
			if (x == '(' && str[i] != ')') {
				return false;
			}
		}
	}
	//扫描完括号序列后再次判断栈是否空，若空，则匹配成功，否则左括号单身
	return isEmpty(s);
}
int main() {
	const char* arr = "{}{[()]}{{{[[[]]]}}}";
	int length = sizeof(arr) / sizeof(char);
	bool match = BracketMatch(arr, length);
	cout << match;
	return 0;
}