/*
* 二叉树的链式存储结构
*	1.每个节点都有来自父亲的指针指向它，因此对于有n个节点的链式二叉树，共有2n个指针，其中n-1个
	有效指针（root没有来自父亲的指针），n+1个空链域

	2.记住非递归的三种遍历代码
*/

#include <iostream>
#include <vector>
typedef char ElemType;
using namespace std;

typedef struct BiTNode {
	char data;//节点数据
	struct BiTNode* lchild, * rchild;//左右孩子指针
	//int ltag = 0, rtag = 0;//线索化标志，=0默认指向自己的孩子，=1指向其前驱或后继
}BiTNode, * BiTree;

BiTNode* p;//要寻找前驱的目标节点
BiTNode* pre = NULL;//当前访问结点的前驱
BiTNode* final = NULL;//记录最终结果


void visit(BiTNode* T) {
	/*打印节点数据*/
	cout << T->data << " ";

	/*寻找中序前驱*/
	//if (T == p) {//若当前访问结点是目标节点
	//	final = pre;//则其前驱pre就是p的中序前驱
	//}
	//else {
	//	pre = T;//pre下移
	//}
}
/*
* 插入左孩子
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
* 插入右孩子
*/
BiTree InsertRight(BiTree Tree, char ch) {
	BiTree p = (BiTree)malloc(sizeof(struct BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	p->data = ch;
	Tree->rchild = p;
	return p;
}
//先序遍历
void PreOrder(BiTree T) {
	if (T) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//中序遍历
void InOrder(BiTree T) {
	if (T) {

		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//后序遍历
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

//先序遍历非递归实现
void PreOrderNonRecursive(BiTree T) {
	vector<BiTNode*>stack;//初始化一个栈
	BiTree p = T;//p是遍历指针
	while (p || !stack.empty())
	{
		if (p) {//一路向左
			visit(p);//访问（打印）根

			stack.push_back(p);
			p = p->lchild;
		}
		else {
			BiTNode* top = stack.back();//获取栈顶元素，待会要拿着它去继续遍历

			stack.pop_back();//弹出栈顶元素

			p = top->rchild;//向右子树走，p赋值为当前节点的右孩子
		}
	}
}
//中序遍历非递归实现
void InOrderNonRecursive(BiTree T) {
	vector<BiTNode*>stack;//初始化一个栈
	BiTree p = T;//p是遍历指针
	while (p || !stack.empty())
	{
		if (p) {//一路向左
			stack.push_back(p);
			p = p->lchild;
		}
		else {
			BiTNode* top = stack.back();//获取栈顶元素，待会要拿着它去继续遍历
			visit(top);//访问（打印）栈顶元素
			stack.pop_back();//弹出栈顶元素

			p = top->rchild;//向右子树走，p赋值为当前节点的右孩子
		}
	}
}
//后序遍历非递归实现
void PostOrderNonRecursive(BiTree T) {
	vector<BiTNode*>stack;//初始化一个栈
	BiTNode* r = NULL;//记录最近访问过的节点
	BiTree p = T;//p是遍历指针

	while (p || !stack.empty())
	{
		if (p) {//一路向左
			stack.push_back(p);
			p = p->lchild;
		}
		else {
			BiTNode* top = stack.back();//获取栈顶元素，待会要拿着它去继续遍历
			if (top->rchild && top->rchild != r) {//若栈顶节点的右子树存在且最近未被访问，则转向右子树
				p = top->rchild;
			}
			else {
				visit(top);//访问（打印）栈顶元素
				stack.pop_back();//弹出栈顶元素
				r = top;//记录最近访问过的节点
				p = NULL;//重置p指针
			}
		}
	}
}
void LevelOrder(BiTree T) {
	vector<BiTNode*>Q;
	Q.push_back(T);//根入队

	BiTNode* cur;//队列中当前访问的节点
	while (!Q.empty()) {
		cur = Q.at(0);
		visit(cur);	//访问队首元素
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
	cout << endl << "先序遍历：" << endl;
	PreOrder(A);

	cout << endl << "先序遍历非递归：" << endl;
	PreOrderNonRecursive(A);
	cout << endl;

	cout << endl << "中序遍历：" << endl;
	InOrder(A);

	cout << endl << "中序遍历非递归：" << endl;
	InOrderNonRecursive(A);
	cout << endl;

	cout << endl << "后序遍历：" << endl;
	PostOrder(A);

	cout << endl << "后序遍历非递归：" << endl;
	PostOrderNonRecursive(A);
	cout << endl;

	cout << endl << "层序遍历：" << endl;
	LevelOrder(A);
	return 0;
}
