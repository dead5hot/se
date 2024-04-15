#include <bits/stdc++.h>
/*
  M = E - N + 2P
  M = Cyclomatic complexity
  E = Edges
  N = Nodes
  P = Number of connected components
*/
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int binarySearch(vector<int> &arr, int n, int key)
{
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main()
{
  vector<int> arr = {10, 20, 100, 70, 5, 80, 55, 35, 60, 90};
  bubbleSort(arr, 10);
  int key = 55;
  int index = binarySearch(arr, arr.size(), key);

  if (index == -1)
    cout << "Element not found" << endl;
  else
    cout << "Element found at index " << index << endl;
  return 0;
}