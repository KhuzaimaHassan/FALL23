#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
int i, j;
for (i = 0; i < n - 1; i++)
// Last i elements are already in place
for (j = 0; j < n - i - 1; j++)
if (arr[j] > arr[j + 1])
swap(arr[j], arr[j + 1]);}

int main (){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the element at "<<i+1<<": ";
        cin>>arr[i];
    }

    bubbleSort(arr, n);

    cout<<"PRINTING SORTED ARRAY\n";
    for(int i=0; i<n; i++){
        cout<<"Element at "<<i+1<<": "<<arr[i]<<endl;
    }
    return 0;
}
