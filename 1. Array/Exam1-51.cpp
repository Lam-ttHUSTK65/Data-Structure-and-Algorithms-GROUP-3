Code:
#include <iostream>
#include <algorithm>
using namespace std;
void quadTuple(int arr[], int n, int target)
{
    sort (arr, arr + n);
    for (int i = 0; i <= n - 4; i++)
    {
        for (int j = i + 1; j <= n - 3; j++)
        {
            int k = target - (arr[i] + arr[j]);
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                if (arr[low] + arr[high] < k) {
                    low++;
                }
                else if (arr[low] + arr[high] > k) {
                    high--;
                }
                else {
                    cout << "(" << arr[i] << " " << arr[j] << " " <<
                            arr[low] << " " << arr[high] << ")\n";
                    low++, high--;
                }
            }
        }
    }
}
int main()
{
    int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int target = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    quadTuple(arr, n, target);
    return 0;
}

Algorithm:
Function quadTuple (A, n, t)
Sort (A, A+n)
For i=0 to n-4 do {
      For j=i+1 to n-3 do {
	k = t – A[i] +A[j], l=j+1, h=n-1
	While (l<h){
	        if A[l] +A[h] <k then l++
	        else if A[l] +A[h] >k then h --
	        else cout A[i], A[j], A[l], A[h]
	        l++, h—
        }
}

//Hien
