#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
/*
* 希尔排序（插入排序）
*/
void ShellSort(int* arr, int n) {
	int i, j, d;//d为希尔增量
	int cnt = 1;
	for (d = n / 2;d >= 1;d /= 2) {//希尔步长变化

		for (i = d;i < n;i++) {
			if (arr[i] < arr[i - d]) {
				int temp = arr[i];
				for (j = i - d;j >= 0 && temp < arr[j];j -= d) {
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}

		}
		cout << "第 " << cnt << " 趟希尔排序步长 d = " << d << ", 此趟排序结果为:  ";
		for (int i = 0;i < n;i++) {
			cout << arr[i] << " ";
		}
		cnt++;
		cout << endl;
	}
}
int main() {
	int arr[8] = { 49,38,65,97,76,13,27,49 };
	ShellSort(arr, 8);
	return 0;
}
