/*
* ƽ������� ���������߶Ȳ�Ϊ0��+1��-1    ƽ������=�������߶�-�������߶�
*
*	�ڶ����������в������ݺ󣬿��ܻᵼ��������ƽ�⡣��Բ��뵼�µĲ�ƽ�⣬���ԴӲ���������ҵ���һ����ƽ��Ľڵ㣬
*	�Դ˽ڵ�Ϊ�����������ǡ���С��ƽ����������������������ƽ��������Ƚڵ��ƽ�����Ӷ����Ϊ�Ϸ�ֵ��
*	LL RR LR RL
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct AVLNode {
	int data;//�ڵ�����
	int balance;//ƽ������
	struct AVLNode* lchild, * rchild;//���Һ���ָ��
}AVLNode, * AVLTree;