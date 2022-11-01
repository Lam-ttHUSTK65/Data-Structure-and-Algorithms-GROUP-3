Code:
#include <iostream>
using namespace std;
void convert(int arr[])
{
    arr[0] = arr[1] = arr[!arr[1]];
    // arr[0] = arr[1] = arr[0] & arr[1];
    // arr[0] = arr[1] -= arr[1];
    // arr[1] = arr[0] -= arr[0];
}
int main()
{
    int first[] = { 0, 1 };
    convert(first);
    cout << first[0] << " " << first[1] << endl;
    int second[] = { 1, 0 };
    convert(second);
    cout << second[0] << " " << second[1] << endl;
    int third[] = { 0, 0 };
    convert(third);
    cout << third[0] << " " << third[1] << endl;
    return 0;
}

Algorithm:
Function convert(A)
A[0]=A[1]=A[!A[1]]
