Code:
#include <stdio.h>
void findLongestSequence(int arr[], int n, int k)
{
    int left = 0;       
    int count = 0;      
    int window = 0;     
    int leftIndex = 0;  
    for (int right = 0; right < n; right++)
    {
        if (arr[right] == 0) {
            count++;
        }
        while (count > k)
        {
		if (arr[left] == 0) {
                count--;
            }
            left++;
        }
        if (right - left + 1 > window)
        {
            window = right - left + 1;
            leftIndex = left;
        }
    }
    if (window == 0) {
        return;
    }
	printf("The longest sequence has length %d from index %d to %d",
            window, leftIndex, (leftIndex + window - 1));
}
int main()
{
    int arr[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    findLongestSequence(arr, n, k);
    return 0;
}

Algorithm:
Function findLongestSequence (A, n, k)
L=0, c=0, w =0, lI =0
For r=0 to n do {
    If A[r] =0 then c++
    While (c>k) {
	If A[l] = 0 then c—else l++}
    If r>l+1>w then w=r-l+1, lI=l
}
If w= 0 then return
Printf The_longest_sequence_has_length w from index lI to lI+w-1
	
//Hien
