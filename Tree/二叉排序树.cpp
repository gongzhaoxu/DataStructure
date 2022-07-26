/*
* 二叉排序树(不允许树中有相同的value)
*			不同序列可能构造出相同的二叉排序树
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BSTTNode {
	int data;//节点数据
	struct BSTTNode* lchild, * rchild;//左右孩子指针
}BSTTNode, * BSTree;

/*
* 查找值为key的节点，非递归
* 若找到,返回指向该节点的指针，否则返回NULL
*/
BSTTNode* BST_Search(BSTree T, int key) {
	while (T && key != T->data) {
		if (key < T->data) {
			T = T->lchild;
		}
		else {
			T = T->rchild;
		}
	}
	return T;

}

/*
* 查找值为key的节点，递归
* 若找到,返回指向该节点的指针，否则返回NULL
*/
BSTTNode* BSTSearch(BSTree T, int key) {
	if (T == NULL) {
		return NULL;
	}
	if (key == T->data) {
		return T;
	}
	else if (key < T->data) {
		return BSTSearch(T->lchild, key);
	}
	else {
		return BSTSearch(T->rchild, key);
	}
}

/*
* 二叉排序树的插入，递归实现
*/
bool BSTInsert(BSTree& T, int key) {
	if (T == NULL) {//树（子树）为空，申请一片内存空间存储
		T = (BSTTNode*)malloc(sizeof(BSTTNode));
		T->data = key;
		T->lchild = NULL;
		T->rchild = NULL;
		return true;
	}
	else if (T->data == key) {//二叉排序树不允许两个节点的值相等，因此不能插入。
		return false;
	}
	else if (key < T->data) {
		return BSTInsert(T->lchild, key);
	}
	else {
		return BSTInsert(T->rchild, key);
	}
}

/*
* 构造二叉排序树，input : Tree , arr<int>[] , length
*/
void CreateBSTree(BSTree& T, int arr[], int n) {
	T = NULL;
	int i = 0;
	while (i < n) {
		BSTInsert(T, arr[i]);
		i++;
	}
}

void visit(BSTTNode* T) {
	/*打印节点数据*/
	cout << T->data << " ";
}
void PreOrder(BSTree T) {
	if (T) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//中序遍历
void InOrder(BSTree T) {
	if (T) {

		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//后序遍历
void PostOrder(BSTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
void LevelOrder(BSTree T) {
	vector<BSTTNode*>Q;
	Q.push_back(T);//根入队

	BSTTNode* cur;//队列中当前访问的节点
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

	BSTree T1, T2;
	int arr1[8] = { 50,66,60,26,21,30,70,68 };
	int arr2[8] = { 50,26,21,30,66,60,70,68 };

	//两个序列虽然不同，但构造出了相同的二叉排序树
	CreateBSTree(T1, arr1, 8);
	CreateBSTree(T2, arr2, 8);


	cout << "TREE1:" << endl;
	cout << "先序遍历：";
	PreOrder(T1);
	cout << endl;
	cout << "中序遍历：";
	InOrder(T1);
	cout << endl;
	cout << "后序遍历：";
	PostOrder(T1);
	cout << endl;
	cout << "层序遍历：";
	LevelOrder(T1);

	cout << endl << "TREE2:" << endl;
	cout << "先序遍历：";
	PreOrder(T2);
	cout << endl;
	cout << "中序遍历：";
	InOrder(T2);
	cout << endl;
	cout << "后序遍历：";
	PostOrder(T2);
	cout << endl;
	cout << "层序遍历：";
	LevelOrder(T2);

	return 0;
}
