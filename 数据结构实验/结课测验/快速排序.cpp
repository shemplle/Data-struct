#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 50 ;

int v[maxn] ;

void swap(int arr[], int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void QuickSort(int arr[], int left, int right)
{
    int i, pivot;

    if (left >= right)
        return;
    pivot = left;
    swap(arr, left, (left + right) / 2);
    for (i = left + 1; i <= right; i++) //单边搜索，可以该为双向搜索（据说快点( ° ▽、° )）
        if (arr[i] < arr[left])
            swap(arr, i, ++pivot);
    swap(arr, left, pivot);
    QuickSort(arr, left, pivot - 1);
    QuickSort(arr, pivot + 1, right);
}

int main() {
	int t; cin >> t;
	for (int i = 1 ; i <= t ; i ++ ) {
		scanf("%d",&v[i]);
	}
	sort(v + 1 ,v + t + 1 ) ;
	//QuickSort(v ,1 ,t );
	for (int i = 1 ; i <= t ; i ++ ) {
		printf("%d ",v[i]) ;
	}
	return 0;
}
