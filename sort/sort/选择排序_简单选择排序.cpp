#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
/*
* ��ѡ������ѡ������
*/
void SelectSort(int* arr, int n) {
	for (int i = 0;i < n - 1;i++) {//i֮ǰ��Ԫ�����ź���
		int min = i;//��СԪ��λ��
		for (int j = i + 1;j < n;j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(arr[min], arr[i]);
		}
	}

	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
}


int main() {
	int arr[9] = { 49,38,65,97,76,13,27,49,1 };
	SelectSort(arr, 9);

	return 0;
}
