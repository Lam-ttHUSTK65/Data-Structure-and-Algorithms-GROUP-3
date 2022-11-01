//Heap Sort Algorithm
function swap(*x,*y)
int LEFT(int i) {return (2*i + 1);}
int RIGHT(int i) {return (2*i + 2);}
function heaptify( A[],n){
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;
    if (left < end && A[left] > A[i]) 
        largest = left;}
    if (right < end && A[right] > A[largest]) 
        largest = right;
    if (largest != i)
        swap(A[i], A[largest]);
        heapify(A, largest)   
function  heapsort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}