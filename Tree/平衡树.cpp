/*
* 平衡二叉树 左右子树高度差为0，+1，-1    平衡因子=左子树高度-右子树高度
*
*	在二叉排序树中插入数据后，可能会导致树不再平衡。针对插入导致的不平衡，可以从插入点往回找到第一个不平衡的节点，
*	以此节点为根的子树就是【最小不平衡子树】，调整该子树至平衡后其祖先节点的平衡因子都会变为合法值。
*	LL RR LR RL
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct AVLNode {
	int data;//节点数据
	int balance;//平衡因子
	struct AVLNode* lchild, * rchild;//左右孩子指针
}AVLNode, * AVLTree;