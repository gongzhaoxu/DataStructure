#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
void InsertSort(int arr[], int n) {
	int i, j;
	for (i = 1;i < n;i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			for (j = i - 1;j >= 0 && temp < arr[j];j--) {
				arr[j + 1] = arr[j];//ÒÀ´ÎºóÒÆ
			}
			arr[j + 1] = temp;
		}

	}
}
int main() {
	int arr[11] = { 1,4,3,6,7,9,2,5,10,8 ,10 };
	InsertSort(arr, 11);
	for (int item : arr) {
		cout << item << " ";
	}
}