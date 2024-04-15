#include <math.h>
#include <iostream>

/*
  BlackBox Testing
*/

using namespace std;

int sortedArr[4][5];
int sortedD1[15];
int sortedD2[2];

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void printArray(int testcaseId, int *arr, int N, bool passed)
{
  cout << "Test Case " << testcaseId << ": {";
  for (int i = 0; i < N; i++)
  {
    cout << arr[i];
    if (i != N - 1)
    {
      cout << ", ";
    }
  }
  cout << "} - ";
  if (passed)
  {
    cout << "Passed\n";
  }
  else
  {
    cout << "Failed\n";
  }
}

void bubbleSort(int originalArr[], int N, int *sortedArr)
{
  int arr[N];
  for (int i = 0; i < N; i++)
  {
    arr[i] = originalArr[i];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
  // copy this array to sortedArr
  for (int i = 0; i < N; i++)
  {
    sortedArr[i] = arr[i];
  }
}

int main()
{
  int n1 = 4, n2 = 5, n3 = 15, n4 = 2;
  int arr[4][5] = {// boundary value
                   {9, 6, 4, 2, 0},
                   {5, 5, 5, 5, 5},
                   // equivalence class
                   {3, 4, 5, 199, 24},
                   {239, 83, 25, 12, 15}};
  int d1[] = {1, 2, 3, 43, 5, 432543, 43, 543, 4312, 346, 87, 12, 2, 76, 76};
  int d2[] = {1982437, 12};

  for (int i = 0; i < n1; i++)
  {
    bubbleSort(arr[i], n2, sortedArr[i]);
  }
  bubbleSort(d1, n3, sortedD1);
  bubbleSort(d2, n4, sortedD2);

  bool testResults[6] = {true, true, true, true, true, true};

  int answers[4][5] = {{0, 2, 4, 6, 9}, {5, 5, 5, 5, 5}, {3, 4, 5, 24, 199}, {12, 15, 25, 83, 239}};
  int d1Answer[] = {1, 2, 2, 3, 5, 12, 43, 43, 76, 76, 87, 346, 543, 4312, 432543};
  int d2Answer[] = {12, 1982437};

  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++)
    {
      if (sortedArr[i][j] != answers[i][j])
      {
        testResults[i] = false;
        break;
      }
    }
  }
  for (int i = 0; i < n3; i++)
  {
    if (sortedD1[i] != d1Answer[i])
    {
      testResults[4] = false;
      break;
    }
  }
  for (int i = 0; i < n4; i++)
  {
    if (sortedD2[i] != d2Answer[i])
    {
      testResults[5] = false;
      break;
    }
  }

  for (int i = 0; i < n1; i++)
  {
    printArray(i + 1, arr[i], n2, testResults[i]);
  }

  printArray(5, d1, n3, testResults[4]);
  printArray(6, d2, n4, testResults[5]);

  cout << "\n";
  return 0;
}