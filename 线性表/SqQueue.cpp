/*
*���е�˳��洢ʵ�֣�frontָ�����Ԫ�أ�rearָ���βԪ�ص���һ��λ�á�
* �߼����Ǹ�ѭ�����С�
*
* �����пպ�������
* 1.��ͨ����ͷ�Ͷ�β���ж��Ƿ�Ϊ�գ���գ�front==rear  ����(rear+1)%MaxSize==front���˷���������һ���ռ�
* 2.�����������Ǹ��ռ䣬���ڽṹ��������size������¼���д�С�����++������--����Ϊ0����գ���ΪMaxSize������
* 3.�����������Ǹ��ռ䣬���ڽṹ��������tag������¼���һ�β���,��Ϊֻ����Ӳ����ᵼ�¶���������Ӳ����ᵼ�¶��пգ�
*	��ˣ�ÿ�����,tag=1,��front==rear && tag==1�����������
*	      ÿ������,tag=0,��front==rear && tag==0������пա�
*/
#include <iostream>
using namespace std;
#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int front, rear;//frontָ���ͷԪ�أ�rearָ���βԪ�صĺ�һ��λ�á�
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
	if (isFull(q)) {//����������
		return false;
	}
	q.data[q.rear] = x;//��Ԫ�ز����β
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}
/*
* delete a element from the front
*/

bool DeQueue(SqQueue& q, int& x) {
	if (q.front == q.rear) {//�������ѿ�
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}
/*
* ��ȡ����Ԫ�ظ���
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