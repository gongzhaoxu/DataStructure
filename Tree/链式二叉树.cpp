/*
* ����������ʽ�洢�ṹ
*	1.ÿ���ڵ㶼�����Ը��׵�ָ��ָ��������˶�����n���ڵ����ʽ������������2n��ָ�룬����n-1��
	��Чָ�루rootû�����Ը��׵�ָ�룩��n+1��������

	2.��ס�ǵݹ�����ֱ�������
*/

#include <iostream>
#include <vector>
typedef char ElemType;
using namespace std;

typedef struct BiTNode {
	char data;//�ڵ�����
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
	//int ltag = 0, rtag = 0;//��������־��=0Ĭ��ָ���Լ��ĺ��ӣ�=1ָ����ǰ������
}BiTNode, * BiTree;

BiTNode* p;//ҪѰ��ǰ����Ŀ��ڵ�
BiTNode* pre = NULL;//��ǰ���ʽ���ǰ��
BiTNode* final = NULL;//��¼���ս��


void visit(BiTNode* T) {
	/*��ӡ�ڵ�����*/
	cout << T->data << " ";

	/*Ѱ������ǰ��*/
	//if (T == p) {//����ǰ���ʽ����Ŀ��ڵ�
	//	final = pre;//����ǰ��pre����p������ǰ��
	//}
	//else {
	//	pre = T;//pre����
	//}
}
/*
* ��������
*/
BiTree InsertLeft(BiTree Tree, char ch) {
	BiTree p = (BiTree)malloc(sizeof(struct BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = ch;
	Tree->lchild = p;
	return p;
}
/*
* �����Һ���
*/
BiTree InsertRight(BiTree Tree, char ch) {
	BiTree p = (BiTree)malloc(sizeof(struct BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = ch;
	Tree->rchild = p;
	return p;
}
//�������
void PreOrder(BiTree T) {
	if (T) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//�������
void InOrder(BiTree T) {
	if (T) {

		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//�������
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

//��������ǵݹ�ʵ��
void PreOrderNonRecursive(BiTree T) {
	vector<BiTNode*>stack;//��ʼ��һ��ջ
	BiTree p = T;//p�Ǳ���ָ��
	while (p || !stack.empty())
	{
		if (p) {//һ·����
			visit(p);//���ʣ���ӡ����

			stack.push_back(p);
			p = p->lchild;
		}
		else {
			BiTNode* top = stack.back();//��ȡջ��Ԫ�أ�����Ҫ������ȥ��������

			stack.pop_back();//����ջ��Ԫ��

			p = top->rchild;//���������ߣ�p��ֵΪ��ǰ�ڵ���Һ���
		}
	}
}
//��������ǵݹ�ʵ��
void InOrderNonRecursive(BiTree T) {
	vector<BiTNode*>stack;//��ʼ��һ��ջ
	BiTree p = T;//p�Ǳ���ָ��
	while (p || !stack.empty())
	{
		if (p) {//һ·����
			stack.push_back(p);
			p = p->lchild;
		}
		else {
			BiTNode* top = stack.back();//��ȡջ��Ԫ�أ�����Ҫ������ȥ��������
			visit(top);//���ʣ���ӡ��ջ��Ԫ��
			stack.pop_back();//����ջ��Ԫ��

			p = top->rchild;//���������ߣ�p��ֵΪ��ǰ�ڵ���Һ���
		}
	}
}
//��������ǵݹ�ʵ��
void PostOrderNonRecursive(BiTree T) {
	vector<BiTNode*>stack;//��ʼ��һ��ջ
	BiTNode* r = NULL;//��¼������ʹ��Ľڵ�
	BiTree p = T;//p�Ǳ���ָ��

	while (p || !stack.empty())
	{
		if (p) {//һ·����
			stack.push_back(p);
			p = p->lchild;
		}
		else {
			BiTNode* top = stack.back();//��ȡջ��Ԫ�أ�����Ҫ������ȥ��������
			if (top->rchild && top->rchild != r) {//��ջ���ڵ�����������������δ�����ʣ���ת��������
				p = top->rchild;
			}
			else {
				visit(top);//���ʣ���ӡ��ջ��Ԫ��
				stack.pop_back();//����ջ��Ԫ��
				r = top;//��¼������ʹ��Ľڵ�
				p = NULL;//����pָ��
			}
		}
	}
}
void LevelOrder(BiTree T) {
	vector<BiTNode*>Q;
	Q.push_back(T);//�����

	BiTNode* cur;//�����е�ǰ���ʵĽڵ�
	while (!Q.empty()) {
		cur = Q.at(0);
		visit(cur);	//���ʶ���Ԫ��
		if (cur->lchild) {
			Q.push_back(cur->lchild);
		}
		if (cur->rchild) {
			Q.push_back(cur->rchild);
		}
		Q.erase(Q.begin());
	}
}
int main() {

	BiTree A = (BiTNode*)malloc(sizeof(BiTNode));
	A->data = 'A';
	A->lchild = NULL;
	A->rchild = NULL;

	BiTNode* B = InsertLeft(A, 'B');
	BiTNode* C = InsertRight(A, 'C');

	BiTNode* D = InsertLeft(B, 'D');
	BiTNode* E = InsertRight(B, 'E');

	BiTNode* F = InsertLeft(C, 'F');
	BiTNode* G = InsertRight(C, 'G');

	InsertLeft(D, 'H');
	InsertRight(D, 'I');

	InsertLeft(F, 'J');
	InsertRight(F, 'K');

	InsertLeft(G, 'L');
	cout << endl << "���������" << endl;
	PreOrder(A);

	cout << endl << "��������ǵݹ飺" << endl;
	PreOrderNonRecursive(A);
	cout << endl;

	cout << endl << "���������" << endl;
	InOrder(A);

	cout << endl << "��������ǵݹ飺" << endl;
	InOrderNonRecursive(A);
	cout << endl;

	cout << endl << "���������" << endl;
	PostOrder(A);

	cout << endl << "��������ǵݹ飺" << endl;
	PostOrderNonRecursive(A);
	cout << endl;

	cout << endl << "���������" << endl;
	LevelOrder(A);
	return 0;
}
