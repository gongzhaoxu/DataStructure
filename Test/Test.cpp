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
* A[low..mid]和A[mid+1,high]各自有序，进行归并
*/
void Merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int* tmp = (int*)malloc(n * sizeof(int));//临时数组
    for (k = low;k <= high;k++) {//先将待归并的二路数据存到tmp数组
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
    while (j<=high)
    {
        arr[k] = tmp[j++];
    }


}
void MergeSort(int *arr,int low,int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    /*TreeNode* t7 = new TreeNode(3);
    TreeNode* t6 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(2,t6,t7);
    TreeNode* t2 = new TreeNode(2,t4,t5);
    TreeNode* t1 = new TreeNode(1, t2, t3);
    Solution s = Solution();
    auto res= s.isSymmetric(t1);
    cout << res;*/
    int arr[n] = { -999,13,45,4,78,4,2,89,21,99 };
    MergeSort(arr, 0,n-1);
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
	return 0;
}
