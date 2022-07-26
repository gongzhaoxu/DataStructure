/*
*ջ����ʽջʵ��,����ͷ���
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
	p->next = s;//ͷ��
	s = p;//�ı�ջͷ
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
* ����ƥ���㷨
*/
bool BracketMatch(const char* str, int length) {
	LiStack s;
	InitStack(s);
	for (int i = 0;i < length;i++) {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {//������ѹջ
			Push(s, str[i]);
		}
		else {
			if (isEmpty(s)) {//����ʱջ�ѿգ��������ŵ���
				return false;
			}
			char x;
			pop(s, x);
			//���������Ų�ƥ��
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
	//ɨ�����������к��ٴ��ж�ջ�Ƿ�գ����գ���ƥ��ɹ������������ŵ���
	return isEmpty(s);
}
int main() {
	const char* arr = "{}{[()]}{{{[[[]]]}}}";
	int length = sizeof(arr) / sizeof(char);
	bool match = BracketMatch(arr, length);
	cout << match;
	return 0;
}