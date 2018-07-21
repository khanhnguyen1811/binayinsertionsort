#include <iostream> 
using namespace std; 
void printarr(int arr[], int n) {
	for (int i = 0;  i < n;  i++)
	{
		cout << arr[i] << " "; 
	}
	cout << "\n";
}
int binarysearch(int arr[], int l, int r, int num) {
	int mid; 
	while (l<=r)
	{
		mid = l + (r - l) / 2;
		if (arr[mid] < num)
		{
			return binarysearch(arr, mid+1, r , num);
			
			//return l = mid + 1; 
		}
		else if(arr[mid] > num)
		{
			return binarysearch(arr, l, mid-1, num);
			//return r = mid - 1; 
		}
		else
		{
			return mid;
		}
	}
}
void binaryinsertion(int arr[], int n) {
	int i, j, ins, temp; 
	for ( i = 1; i < n; i++)
	{
		ins = binarysearch(arr, 0, i, arr[i]);
		temp = arr[i];
		for (j = i-1; j >= ins; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[ins] = temp;
	}
}
int main() {
	int arr[100], i, n; 
	cout << "nhap size "; cin >> n; 
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	binaryinsertion(arr, n);
	printarr(arr, n);
	return 0;
}