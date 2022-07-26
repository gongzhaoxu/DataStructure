/*
* 队列的链式存储实现，front指向队首元素，rear指向队尾元素。带头节点
*/
#include <iostream>
using namespace std;

//链式队列节点数据结构
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

//链式队列
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

/*
* Init a new Queue
*/
void InitQueue(LinkQueue& q) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	q.front = p;
	q.rear = p;
	q.front->next == NULL;
}
/*
* isEmpty?
*/
bool isEmpty(LinkQueue q) {
	if (q.front->next == NULL) {
		return true;
	}
	return false;
}

/*
* new a element to the rear
*/
bool enQueue(LinkQueue& q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;	//s->next = q.rear->next;
	q.rear->next = s;
	q.rear = s;
	return true;
}
/*
* delete a element from the front
*/

bool DeQueue(LinkQueue& q, int& x) {
	if (q.front == q.rear) {//若队列已空
		return false;
	}
	LinkNode* s = q.front->next;
	x = s->data;
	q.front->next = s->next;
	if (s->next == NULL) {//若s是最后一个元素
		q.rear = q.front;
	}
	free(s);
	return true;
}

void Print(LinkQueue q) {
	LinkNode* s = q.front->next;
	while (s) {
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}
int main() {
	LinkQueue q;
	InitQueue(q);

	enQueue(q, 15);
	enQueue(q, 234);
	enQueue(q, 5);
	enQueue(q, 532);
	enQueue(q, 7);
	Print(q);

	int x;
	DeQueue(q, x);
	Print(q);
	DeQueue(q, x);
	Print(q);
	DeQueue(q, x);
	Print(q);

	enQueue(q, -10);
	enQueue(q, 36);
	enQueue(q, 52);
	enQueue(q, 85);
	enQueue(q, 13);
	Print(q);

	enQueue(q, 5);
	enQueue(q, 532);
	Print(q);

	DeQueue(q, x);
	Print(q);
	DeQueue(q, x);
	Print(q);
	enQueue(q, 5);
	Print(q);

	enQueue(q, 15);
	enQueue(q, 234);
	enQueue(q, 5);
	enQueue(q, 532);
	enQueue(q, 7);
	Print(q);
	enQueue(q, 15);
	enQueue(q, 234);
	enQueue(q, 5);
	enQueue(q, 532);
	enQueue(q, 7);
	Print(q);
	return 0;
}