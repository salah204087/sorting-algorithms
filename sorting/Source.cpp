#include <iostream>
using namespace std;

/*******************************************selection sort**********************************************************/
void selection_sort(int arr[],int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
				swap(arr[min], arr[i]);
		}
	}
}
/*******************************************Bubble sort**********************************************************/
void Bubble_sort(int arr[], int n)
{
	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;
			}	
		}
		if (flag == true)
			break;
	}
}
/*******************************************inseration sort**********************************************************/
void inseration_sort(int arr[],int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
/*******************************************merge sort**********************************************************/
void merge(int arr[], int l, int m, int r)  
{
	int i, j, k;
	int n1 = m - l + 1;                  
	int n2 = r - m;            
	int* L = new int[n1], * R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/*******************************************quick sort**********************************************************/
int partition(int arr[], int iBegin, int jEnd) {
	int i = iBegin;
	int j = jEnd;
	int pivLoc = i;
	while (true)
	{
		while (arr[pivLoc] <= arr[j] && pivLoc != j)
		{
			j--;
		}
		if (pivLoc == j)
			break;
		else if (arr[pivLoc] > arr[j])
		{
			swap(arr[j], arr[pivLoc]);
			pivLoc = j;
		}

		while (arr[pivLoc] >= arr[i] && pivLoc != i)
		{
			i++;
		}
		if (pivLoc == i)
			break;
		else if (arr[pivLoc] < arr[i])
		{
			swap(arr[i], arr[pivLoc]);
			pivLoc = i;
		}
	}
	return pivLoc;
}


void quick_sort(int arr[], int l, int h)
{

	if (l < h) {
		int piv = partition(arr, l, h);
		quick_sort(arr, l, piv - 1);
		quick_sort(arr, piv + 1, h);
	}

}
/*******************************************heap sort**********************************************************/

void heapify(int arr[], int n, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	if (l<n && arr[l]>arr[max])
		max = l;
	if (r<n && arr[r]>arr[max])
		max = r;

	if (max != i) {
		swap(arr[i], arr[max]);
		heapify(arr, n, max);
	}
}

void buildHeap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}

void heap_sort(int arr[], int n)
{

	buildHeap(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 65,22,10,12,30,80,45,21 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr,n);
	print(arr, n);
}