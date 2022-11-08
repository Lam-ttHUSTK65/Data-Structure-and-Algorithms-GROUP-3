#include <iostream>
using namespace std;
int main(){
	int a[]={1,-3,9,7,-8,6,10}; 
    int n = sizeof(a)/4; 
    int maxsum = 0; 
    int s = 0;
    int b = 0, e = n-1; 
    for (int i = 0; i < n; i++) {
        for(int j=i;j<n;j++)
        {
            s=0; 
            for(int k=i;k<=j;k++)
            {
                s+=a[k]; 
            }
            if(maxsum < s)
            {
                maxsum = s;
                b = i; e = j;
            }
        }
    }
 
    cout<<    maxsum     <<"\n";
    for(int i=b;i<=e;i++) cout<<a[i]<<" ";
	return 0;
}