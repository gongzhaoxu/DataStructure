#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/*
* 将以root为根的子树调整为大根堆
*/
void HeapAdjust(int arr[], int root, int len) {
    arr[0] = arr[root];//暂存根节点数据
    for (int i = 2 * root;i <= len;i *= 2) {
        if (i < len && arr[i] < arr[i + 1]) {
            i++;
        }
        if (arr[0] >= arr[i]) {
            break;//不用调整
        }
        else {
            arr[root] = arr[i];//大数据往上提
            root = i;//修改完以root为根的子树后 ，还得继续检测
        }
    }
    arr[root] = arr[0];
}


/*
* 建立大根堆
*/
void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2;i > 0;i--) {
        HeapAdjust(arr, i, n);
    }
}
void HeapSort(int arr[], int len) {
    BuildMaxHeap(arr, len);//构建大根堆
    for (int i = len;i > 1;i--) {
        swap(arr[1], arr[i]);//交换堆顶元素和堆底元素
        HeapAdjust(arr, 1, i - 1);
    }

}
int main() {
    int arr[11] = { -999,13,45,4,78,4,2,89,21,99 };
    HeapSort(arr, 10);
    for (int i = 2;i <= 10;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
