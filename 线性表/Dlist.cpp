/*
*���Ա��˫����ʵ��,��ͷ���
* ˫����ı�ͷ��ǰ��ָ��գ���β�ĺ��ָ��գ�����û��ǰ���ģ���Ϊ������һ��Dnode�ڵ�
*/

#include <iostream>
using namespace std;

int g_data = 0;

typedef struct DNode {
	int data = -1;
	struct DNode* next, * prior;
}DNode, * DLinkList;

bool InitDLinkList(DLinkList& L) {
	L = (DLinkList)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	L->prior = NULL;
	return true;
}
/*
* ��p�ڵ�����s�ڵ�
*/
void InsertNextNode(DNode* p, DNode* s) {

	s->next = p->next;
	if (p->next != NULL) {//��p�ڵ��̲�Ϊ�գ�����p�ĺ�̵�ǰ��ָ��s�����򣬲���ָ��ǰ����
		p->next->prior = s;
	}
	p->next = s;
	s->prior = p;
}
/*
* ɾ��p�ĺ��
*/
bool DeleteNextNode(DNode* p) {
	if (p == NULL) {
		return false;
	}
	DNode* s = p->next;
	if (s == NULL) {//��pû�к��
		return false;
	}
	p->next = s->next;
	if (s->next != NULL) {//��p�ĺ�̲������һ���ڵ�
		s->next->prior = p;
	}
	free(s);
	return true;
}
/*
* ����һ��˫����
*/
void DestoryList(DLinkList& L) {
	while (L->next != NULL)
	{
		DeleteNextNode(L);
	}
	free(L);
	L = NULL;
}
/*
* ������
*/
void PrintBackword(DNode* L) {
	if (L->prior == NULL) {//������ͷ���
		L = L->next;
	}
	while (L)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}
/*
* ��ǰ����
*/
void PrintForword(DNode* L) {
	while (L->prior != NULL)//������ͷ���
	{
		cout << L->data << " ";
		L = L->prior;
	}
	cout << endl;
}
int main() {
	DLinkList L;
	InitDLinkList(L);

	DNode* s1 = (DNode*)malloc(sizeof(DNode));
	s1->data = 15;
	InsertNextNode(L, s1);

	DNode* s2 = (DNode*)malloc(sizeof(DNode));
	s2->data = 12;
	InsertNextNode(s1, s2);

	DNode* s3 = (DNode*)malloc(sizeof(DNode));
	s3->data = 99;
	InsertNextNode(s2, s3);

	DNode* s4 = (DNode*)malloc(sizeof(DNode));
	s4->data = 1;
	InsertNextNode(s3, s4);

	PrintBackword(L);

	PrintBackword(s2);


	PrintForword(L);
	PrintForword(s4);
	PrintForword(s2);
	//DeleteNextNode(s2);
	return 0;
}