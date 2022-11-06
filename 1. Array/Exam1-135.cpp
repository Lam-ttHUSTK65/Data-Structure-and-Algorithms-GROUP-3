/*
Problem:
    Given a set of positive integers and an integer k, check if there is any non-empty subset that sums to k
Algorithm:
    1. subsetS8m returns true if there exists a subsequence of `A[0…n]` with the given sum
    2. vector<int> A
	3. int main()
*/ 

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> const &A, int k)
{
    int n = A.size();
    bool T[n + 1][k + 1];
    for (int j = 1; j <= k; j++) {T[0][j] = false;}
    for (int i = 0; i <= n; i++) {T[i][0] = true;}
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (A[i - 1] > j) {T[i][j] = T[i - 1][j];}
            else {T[i][j] = T[i - 1][j] || T[i - 1][j - A[i - 1]];}
        }
    }
    return T[n][k];
}

int main()
{
    vector<int> A = { 7, 3, 2, 5, 8 };
    int k = 18;
    if (subsetSum(A, k)) {cout << "Subsequence with the given sum exists";}
    else {cout << "Subsequence with the given sum does not exist";}
    return 0;
}
