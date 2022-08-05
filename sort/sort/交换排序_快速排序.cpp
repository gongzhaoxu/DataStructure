#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int Partition(int* arr, int low, int high) {
	int pivot = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= pivot) {
			high--;
		}
		arr[low] = arr[high];//比pivot小的移动到左边
		while (low < high && arr[low] <= pivot) {
			low++;
		}
		arr[high] = arr[low];//比pivot大的移动到右边
	}
	//循环结束时low=high，此时此位置即为pivot的最终位置
	arr[low] = pivot;
	return low;
}

/*
* 快速排序（交换排序）
*/
void QuickSort(int* arr, int low, int high) {
	if (low < high) {
		int pivotPos = Partition(arr, low, high);
		QuickSort(arr, low, pivotPos - 1);
		QuickSort(arr, pivotPos + 1, high);
	}
}



int main() {
	int arr1[9] = { 49,38,65,97,76,13,27,49,1 };
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	QuickSort(arr, 0, 8);
	for (int i = 0;i < 9;i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
