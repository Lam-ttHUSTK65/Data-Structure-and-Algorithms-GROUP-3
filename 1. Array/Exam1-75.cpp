/*
Algorithm:
Function findPairs (A, n)
unordered_map<int, vector<Pair>> m
For i=0 to n-1 do {
   For j=i+1 to n do {
 	sum = A[i]+A[j]
	If m.find(sum) != m.end(){
	    For for (auto pair: m.find(sum)->second){
m = pair.first, n = pair.second;
 if (m != i && m != j) && (n != i && n != j) then   cout  (A[i], A[j]) , (A[m],A[n])                        
return;
}
                   }
            m[sum].push_back({i, j});
	}
    }
cout << "No non-overlapping pairs present";

//Hien
*/

//Code:
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


