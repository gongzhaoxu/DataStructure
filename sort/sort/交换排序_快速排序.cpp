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
		arr[low] = arr[high];//��pivotС���ƶ������
		while (low < high && arr[low] <= pivot) {
			low++;
		}
		arr[high] = arr[low];//��pivot����ƶ����ұ�
	}
	//ѭ������ʱlow=high����ʱ��λ�ü�Ϊpivot������λ��
	arr[low] = pivot;
	return low;
}

/*
* �������򣨽�������
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
