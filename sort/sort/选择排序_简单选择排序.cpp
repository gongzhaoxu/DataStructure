#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
/*
* 简单选择排序（选择排序）
*/
void SelectSort(int* arr, int n) {
	for (int i = 0;i < n - 1;i++) {//i之前的元素已排好序
		int min = i;//最小元素位置
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
