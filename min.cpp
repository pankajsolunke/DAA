#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int smallest = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	
	if (left_child < n && arr[left_child] < arr[smallest])
		smallest = left_child;
		
	if (right_child < n && arr[right_child] < arr[smallest])
		smallest = right_child;
		
	if (smallest != i)
	{
		swap(arr[i], arr[smallest]);
		heapify(arr, n, smallest);
	}
}
void buildHeap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
}
	
void printHeap(int arr[], int n)
{
	
	cout << "Min Heap: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int arr[] = {4, 10, 3, 5, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	buildHeap(arr, n);
	
	return 0;
}
