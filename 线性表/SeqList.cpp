/*
*���Ա��˳���ʵ��
*/
#include <iostream>
using namespace std;
#define InitSize 10

typedef struct {
	int* data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList& L) {
	L.data = (int*)malloc(sizeof(int) * InitSize);
	L.MaxSize = InitSize;
	L.length = 0;
}

void IncreaseSize(SeqList& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));
	for (int i = 0;i < L.length;i++) {
		L.data[i] = p[i];
	}

	L.MaxSize += len;
	free(p);
}

void PrintList(SeqList L) {
	for (int i = 0;i < L.length;i++) {
		printf_s("%d   ", L.data[i]);
	}
	printf_s("����Ϊ:%d", L.length);
	printf_s("��󳤶�Ϊ:%d", L.MaxSize);
	cout << endl;
}
int InsertList(SeqList& L, int i, int e) {

	if (i<1 || i>L.length + 1) {
		return 1;
	}
	if (L.length == L.MaxSize) {
		return 2;
	}
	for (int j = L.length;j >= i;j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return 0;
}
int DeleteList(SeqList& L, int i, int& e) {

	if (i<1 || i>L.length) {
		return 1;
	}
	e = L.data[i - 1];
	for (int j = i;j < L.length;j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	cout << "ɾ���˵�" << i << "������Ϊ��" << e << endl;
	return 0;
}
/*
* ɾ��˳���������ֵΪx�����ݣ�Ҫ��ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
*/
void Del_X(SeqList& L, int x) {
	int k = 0;//��¼��Ϊx�ļ�¼���±�
	for (int i = 0;i < L.length;i++) {
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

}
/*
* ɾ������˳�����ֵ��Χ��s-t�ڵ�����
*/
bool DelRangeOrderedList(SeqList& L, int s, int t) {
	if (s >= t) {
		return false;
	}
	int i, j;
	for (i = 0;i < L.length && L.data[i] < s;i++) {

	}
	if (i >= L.length) {
		return false;
	}
	for (j = i;j < L.length && L.data[j] <= t;j++) {
	}
	for (;j < L.length;i++, j++) {
		L.data[i] = L.data[j];
	}
	L.length = i;
	return true;
}
/*
* ɾ������˳�����ֵ��Χ��s-t�ڵ����ݣ�����s��t
*/
bool DelRangeInUnOrderedList(SeqList& L, int s, int t) {
	if (s >= t) {
		return false;
	}
	int k = 0, i;//��¼��Ϊs-t��Χ�����ݸ���������index��
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i]<s || L.data[i]>t) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
	return true;
}
int main() {
	SeqList L;
	InitList(L);
	InsertList(L, 1, 52);
	InsertList(L, 2, 10);
	InsertList(L, 3, 5);
	InsertList(L, 4, 99);
	InsertList(L, 5, 45);
	InsertList(L, 6, 1);
	InsertList(L, 7, 15);
	InsertList(L, 8, 77);

	PrintList(L);

	DelRangeInUnOrderedList(L, 5, 45);

	PrintList(L);
	return 0;
}