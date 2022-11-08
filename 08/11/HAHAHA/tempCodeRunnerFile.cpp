#include <bits/stdc++.h>
// using namespace std;
 
// int maxSubArraySum(int a[], int size)
// {
//     int maxSoFar = INT_MIN, maxEnd = 0;
//     for (int i = 0; i < size; i++) {
//         maxEnd = maxEnd + a[i];
//         if (maxSoFar < maxEnd)
//             maxSoFar = maxEnd;
//         if (maxEnd < 0)
//             maxEnd = 0;
//     }
//     return maxSoFar;
// }
 
// int main()
// {
//     int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
//     int n = sizeof(a) / sizeof(a[0]);
//     int maxSum = maxSubArraySum(a, n);
//     cout << "Maximum sum is " << maxSum;
//     return 0;
// }