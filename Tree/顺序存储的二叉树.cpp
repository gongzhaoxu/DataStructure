/*
* 二叉树的顺序存储数据结构
*
*	对于完全二叉树，存储密度大，对于编号为i的节点，左孩子为2*i，右孩子为2*i-1，父亲为floor(i/2);
*	若该完全二叉树节点i有左孩子，则2*i<=n;若该完全二叉树节点i有右孩子，则2*i+1<=n
*
*	对于普通的二叉树，存储密度低，必须按照完全二叉树的编号方式进行编号，否则数组下标无法反应数的逻辑结果
*	对于编号为i的节点，左孩子为2*i，右孩子为2*i-1，父亲为floor(i/2);
*	若该二叉树节点i有左孩子，则2*i这个节点的isEmpty==false;若该完全二叉树节点i有右孩子，则2*i+1这个节点的isEmpty==false
*
*/

#include <iostream>
#define MaxSize 100
using namespace std;

struct TreeNode {
	int value;//节点数据
	bool isEmpty;//节点是否非空
};

TreeNode t[MaxSize];

int main() {
	return 0;
}
