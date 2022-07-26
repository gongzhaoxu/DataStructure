/*
*队列的顺序存储实现，front指向队首元素，rear指向队尾元素的下一个位置。
* 逻辑上是个循环队列。
*
* 关于判空和判满：
* 1.若通过队头和队尾来判断是否为空，则空：front==rear  满：(rear+1)%MaxSize==front，此方法会牺牲一个空间
* 2.若不想牺牲那个空间，则：在结构体中增加size变量记录队列大小，入队++，出队--，若为0，则空，若为MaxSize，则满
* 3.若不想牺牲那个空间，则：在结构体中增加tag变量记录最近一次操作,因为只有入队操作会导致队列满，入队操作会导致队列空，
*	因此，每当入队,tag=1,若front==rear && tag==1，则队列满。
*	      每当出队,tag=0,若front==rear && tag==0，则队列空。
*/
#include <iostream>
using namespace std;
#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int front, rear;//front指向队头元素，rear指向队尾元素的后一个位置。
}SqQueue;
/*
* Init a new Stack
*/
void InitQueue(SqQueue& q) {
	q.front = 0;
	q.rear = 0;
}
/*
* isEmpty?
*/
bool isEmpty(SqQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	return false;
}
bool isFull(SqQueue q) {
	return (q.rear + 1) % MaxSize == q.front;
}
/*
* new a element to the rear
*/
bool EnQueue(SqQueue& q, int x) {
	if (isFull(q)) {//若队列已满
		return false;
	}
	q.data[q.rear] = x;//新元素插入队尾
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}
/*
* delete a element from the front
*/

bool DeQueue(SqQueue& q, int& x) {
	if (q.front == q.rear) {//若队列已空
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}
/*
* 获取队列元素个数
*/
int getNum(SqQueue q) {
	return (q.rear + MaxSize - q.front) % MaxSize;
}

void Print(SqQueue q) {

	while (q.front != q.rear) {
		cout << q.data[q.front] << " ";
		q.front = (q.front + 1) % MaxSize;
	}
	cout << endl;
}
int main() {
	SqQueue q;
	InitQueue(q);

	EnQueue(q, 15);
	EnQueue(q, 234);
	EnQueue(q, 5);
	EnQueue(q, 532);
	EnQueue(q, 7);
	Print(q);

	int x;
	DeQueue(q, x);
	Print(q);
	DeQueue(q, x);
	Print(q);
	DeQueue(q, x);
	Print(q);

	EnQueue(q, -10);
	EnQueue(q, 36);
	EnQueue(q, 52);
	EnQueue(q, 85);
	EnQueue(q, 13);
	Print(q);

	EnQueue(q, 5);
	EnQueue(q, 532);
	Print(q);

	DeQueue(q, x);
	Print(q);
	DeQueue(q, x);
	Print(q);
	EnQueue(q, 5);
	Print(q);

	return 0;
}