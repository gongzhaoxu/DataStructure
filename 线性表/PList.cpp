/*
*���Ա������ʵ��,��ͷ���
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
* Ѱ�ҵ�i���ڵ�
*/
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	LNode* p = L;//pָ���һ�����ݽڵ�
	int j = 0;//��ǰɨ���˵ڼ����ڵ�
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

/*
* ��λ����룬��ͷ������һ�����ݽڵ�Ϊ1��
*/
bool InsertList(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i - 1);
	if (p == NULL) {//pΪ��i-1���ڵ㣬Ҫ��p֮����룬��P��Ϊ���ˣ���Ȼ������������
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}
/*
* ��λ��ɾ��λ��Ϊi�Ľڵ�
*/
bool DeleteList(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i - 1);
	if (p == NULL) {//pΪ��i-1���ڵ㣬Ҫ��p֮����룬��P��Ϊ���ˣ���Ȼ������������
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
* ����ͷ����β�巨��������ֻ��Ե�һ���ڵ������⴦��������β�巨һ��
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
*����ͷ����ͷ�巨��������,ע��ÿ�β����ͷ��㶼��ı䡣����
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
* β�巨��������
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
*ͷ�巨��������
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
* ������ת��ͷ�巨
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
	cout << "ɾ����Ԫ��Ϊ��" << e << endl;*/
	//PrintList(L);

	return 0;
}