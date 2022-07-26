/*
*线性表的链表实现,带头结点
*/

#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

/*
* 寻找第i个节点
*/
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	LNode* p = L;//p指向第一个数据节点
	int j = 0;//当前扫到了第几个节点
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

/*
* 按位序插入，除头结点外第一个数据节点为1号
*/
bool InsertList(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i - 1);
	if (p == NULL) {//p为第i-1个节点，要在p之后插入，若P都为空了，显然超出链表长度了
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}
/*
* 按位序删除位序为i的节点
*/
bool DeleteList(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i - 1);
	if (p == NULL) {//p为第i-1个节点，要在p之后插入，若P都为空了，显然超出链表长度了
		return false;
	}
	LNode* next = p->next;
	p->next = next->next;
	e = next->data;
	free(next);
	return true;
}
void PrintList(LinkList L) {
	LNode* t = L->next;
	while (t != NULL) {
		cout << t->data << " -> ";
		t = t->next;
	}
	cout << endl;
}
void PrintListWithoutHead(LinkList L) {
	LNode* t = L;
	while (t != NULL) {
		cout << t->data << " -> ";
		t = t->next;
	}
	cout << endl;
}
/*
* 不带头结点的尾插法建立链表，只需对第一个节点做特殊处理，其余与尾插法一样
*/
LinkList List_Tail_WithoutHead(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	LNode* tail = L;
	LNode* s = L;
	int x;
	scanf_s("%d", &x);
	L->data = x;
	scanf_s("%d", &x);
	while (x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		tail->next = s;
		tail = s;
		scanf_s("%d", &x);
	}
	tail->next = NULL;
	return L;
}
/*
*不带头结点的头插法建立链表,注意每次插入后头结点都会改变。！！
*/
LinkList List_Head_WithoutHead(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s = NULL;
	int x;
	scanf_s("%d", &x);
	L->data = x;

	scanf_s("%d", &x);
	while (x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L;
		L = s;
		scanf_s("%d", &x);
	}
	return L;
}
/*
* 尾插法建立链表
*/
LinkList List_Tail(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	LNode* tail = L;
	LNode* s = L;
	int x;
	scanf_s("%d", &x);
	while (x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		tail->next = s;
		tail = s;
		scanf_s("%d", &x);
	}
	tail->next = NULL;
	return L;
}
/*
*头插法建立链表
*/
LinkList List_Head(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s = L;
	int x;
	scanf_s("%d", &x);
	while (x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}
/*
* 链表逆转，头插法
* 
*/
LinkList LinkReverse(LinkList& x) {
	LinkList L = (LinkList)malloc(sizeof(LNode));//create a head node
	L->next = NULL;
	LNode* s = L;
	while (x) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x->data;
		s->next = L->next;
		L->next = s;
		x = x->next;
	}
	return L;
}
int main() {
	LinkList L;
	LinkList X1 = List_Head_WithoutHead(L);
	PrintListWithoutHead(X1);
	/*LinkList X2 = LinkReverse(X1);
	PrintList(X2);*/


	/*InitList(L);
	InsertList(L, 1, 10);
	InsertList(L, 2, 99);
	InsertList(L, 3, 1239);
	InsertList(L, 4, 678);
	InsertList(L, 5, 56);
	PrintList(L);
	int e = -1;
	DeleteList(L, 1, e);
	cout << "删除的元素为：" << e << endl;*/
	//PrintList(L);

	return 0;
}