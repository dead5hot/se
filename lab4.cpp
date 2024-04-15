#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/*
Error found:

• 1st error is found in bubble Sort.
Solve using create new variable count in place of array (vector size) because our vectgor is fixed in size but -1 is
breaking point. So given vector in bubble sort is dynamic in natur. but we notice that count is the actual size of
needed array so we add (int cont) in bublle sort.

• 2nd Error in calculate median return type is double but in code int
*/

void bubbleSort(vector<int> &arr, int count);
double calculateMedian(vector<int> &arr, int count);

int main()
{
  vector<int> arr(10, 0);
  int input, count = 0;

  cout << "Enter up to 10 integers (press -1 to stop):\n";
  while (count < 10)
  {
    cin >> input;
    if (input == -1)
    {
      break;
    }
    arr[count++] = input;
  }

  bubbleSort(arr, count);
  double median = calculateMedian(arr, count);
  cout << "Medain : " << median << endl;
  return 0;
}
