/*
*线性表的双链表实现,带头结点
* 双链表的表头的前驱指向空，表尾的后继指向空，空是没有前驱的，因为它不是一个Dnode节点
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
* 在p节点后插入s节点
*/
void InsertNextNode(DNode* p, DNode* s) {

	s->next = p->next;
	if (p->next != NULL) {//若p节点后继不为空，则让p的后继的前驱指向s，否则，不用指向前驱。
		p->next->prior = s;
	}
	p->next = s;
	s->prior = p;
}
/*
* 删除p的后继
*/
bool DeleteNextNode(DNode* p) {
	if (p == NULL) {
		return false;
	}
	DNode* s = p->next;
	if (s == NULL) {//若p没有后继
		return false;
	}
	p->next = s->next;
	if (s->next != NULL) {//若p的后继不是最后一个节点
		s->next->prior = p;
	}
	free(s);
	return true;
}
/*
* 销毁一个双链表
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
* 向后遍历
*/
void PrintBackword(DNode* L) {
	if (L->prior == NULL) {//不遍历头结点
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
* 向前遍历
*/
void PrintForword(DNode* L) {
	while (L->prior != NULL)//不遍历头结点
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