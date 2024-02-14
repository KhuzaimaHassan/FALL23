#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
int i, key, j;
for (i = 1; i < n; i++){
key = arr[i];
j = i - 1;
// Move elements of arr[0..i-1], that are greater than
// key, to one position ahead of their current position
while (j >= 0 && arr[j] > key){
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}




int main (){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the element at "<<i+1<<": ";
        cin>>arr[i];
    }

    insertionSort(arr, n);

    cout<<"PRINTING SORTED ARRAY\n";
    for(int i=0; i<n; i++){
        cout<<"Element at "<<i+1<<": "<<arr[i]<<endl;
    }
    return 0;
}
