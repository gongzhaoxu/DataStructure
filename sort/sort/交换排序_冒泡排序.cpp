#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
/*
* ð�����򣨽�����������
*/
void BubbleSortAsc(int* arr, int n) {
	for (int i = 0;i < n - 1;i++) {//i֮ǰ��Ԫ�����ź���
		bool flag = false;//�����Ƿ�������
		for (int j = n - 1;j > i;j--) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}

	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
}

/*
* ð�����򣨽������򣩽���
*/
void BubbleSortDesc(int* arr, int n) {
	for (int i = n - 1;i > 0;i--) {//i֮���Ԫ�����ź���
		bool flag = false;//�����Ƿ�������
		for (int j = 0;j < i;j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
	cout << endl;
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[9] = { 49,38,65,97,76,13,27,49,1 };
	BubbleSortAsc(arr, 9);
	BubbleSortDesc(arr, 9);

	return 0;
}
