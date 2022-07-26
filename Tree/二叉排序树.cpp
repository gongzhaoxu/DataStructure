/*
* ����������(��������������ͬ��value)
*			��ͬ���п��ܹ������ͬ�Ķ���������
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BSTTNode {
	int data;//�ڵ�����
	struct BSTTNode* lchild, * rchild;//���Һ���ָ��
}BSTTNode, * BSTree;

/*
* ����ֵΪkey�Ľڵ㣬�ǵݹ�
* ���ҵ�,����ָ��ýڵ��ָ�룬���򷵻�NULL
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
* ����ֵΪkey�Ľڵ㣬�ݹ�
* ���ҵ�,����ָ��ýڵ��ָ�룬���򷵻�NULL
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
* �����������Ĳ��룬�ݹ�ʵ��
*/
bool BSTInsert(BSTree& T, int key) {
	if (T == NULL) {//����������Ϊ�գ�����һƬ�ڴ�ռ�洢
		T = (BSTTNode*)malloc(sizeof(BSTTNode));
		T->data = key;
		T->lchild = NULL;
		T->rchild = NULL;
		return true;
	}
	else if (T->data == key) {//���������������������ڵ��ֵ��ȣ���˲��ܲ��롣
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
* ���������������input : Tree , arr<int>[] , length
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
	/*��ӡ�ڵ�����*/
	cout << T->data << " ";
}
void PreOrder(BSTree T) {
	if (T) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//�������
void InOrder(BSTree T) {
	if (T) {

		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//�������
void PostOrder(BSTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
void LevelOrder(BSTree T) {
	vector<BSTTNode*>Q;
	Q.push_back(T);//�����

	BSTTNode* cur;//�����е�ǰ���ʵĽڵ�
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

	BSTree T1, T2;
	int arr1[8] = { 50,66,60,26,21,30,70,68 };
	int arr2[8] = { 50,26,21,30,66,60,70,68 };

	//����������Ȼ��ͬ�������������ͬ�Ķ���������
	CreateBSTree(T1, arr1, 8);
	CreateBSTree(T2, arr2, 8);


	cout << "TREE1:" << endl;
	cout << "���������";
	PreOrder(T1);
	cout << endl;
	cout << "���������";
	InOrder(T1);
	cout << endl;
	cout << "���������";
	PostOrder(T1);
	cout << endl;
	cout << "���������";
	LevelOrder(T1);

	cout << endl << "TREE2:" << endl;
	cout << "���������";
	PreOrder(T2);
	cout << endl;
	cout << "���������";
	InOrder(T2);
	cout << endl;
	cout << "���������";
	PostOrder(T2);
	cout << endl;
	cout << "���������";
	LevelOrder(T2);

	return 0;
}
