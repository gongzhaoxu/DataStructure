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
* ����rootΪ������������Ϊ�����
*/
void HeapAdjust(int arr[], int root, int len) {
    arr[0] = arr[root];//�ݴ���ڵ�����
    for (int i = 2 * root;i <= len;i *= 2) {
        if (i < len && arr[i] < arr[i + 1]) {
            i++;
        }
        if (arr[0] >= arr[i]) {
            break;//���õ���
        }
        else {
            arr[root] = arr[i];//������������
            root = i;//�޸�����rootΪ���������� �����ü������
        }
    }
    arr[root] = arr[0];
}


/*
* ���������
*/
void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2;i > 0;i--) {
        HeapAdjust(arr, i, n);
    }
}
void HeapSort(int arr[], int len) {
    BuildMaxHeap(arr, len);//���������
    for (int i = len;i > 1;i--) {
        swap(arr[1], arr[i]);//�����Ѷ�Ԫ�غͶѵ�Ԫ��
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
