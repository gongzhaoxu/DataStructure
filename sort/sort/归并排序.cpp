#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define n 10

/*
* A[low..mid]��A[mid+1,high]�������򣬽��й鲢
*/
void Merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int* tmp = (int*)malloc(n * sizeof(int));//��ʱ����
    for (k = low;k <= high;k++) {//�Ƚ����鲢�Ķ�·���ݴ浽tmp����
        tmp[k] = arr[k];
    }
    for (i = low, j = mid + 1, k = i;i <= mid && j <= high;k++) {
        if (tmp[i] <= tmp[j]) {
            arr[k] = tmp[i++];
        }
        else {
            arr[k] = tmp[j++];
        }
    }
    while (i <= mid) {
        arr[k] = tmp[i++];
    }
    while (j <= high)
    {
        arr[k] = tmp[j++];
    }


}
void MergeSort(int* arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int arr[n] = { -999,13,45,4,78,4,2,89,21,99 };
    MergeSort(arr, 0, n - 1);
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
