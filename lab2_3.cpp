#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int maximumToys(int arr[], int n, int k) {
    selectionSort(arr, n);
    int count = 0;
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        if (totalCost + arr[i] <= k) {
            totalCost += arr[i];
            count++;
       cout<<"\nYou can buy:  "<<arr[i];
        } else {
            break;
        }
    }
    return count;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the element no "<<i+1<<": ";
        cin >> arr[i];
    }
    int k;
    cout << "Enter the budget: ";
    cin >> k;
    selectionSort(arr, n);
    cout<<"\tSorted array of elements is \n";
    for(int i = 0;i<n; i++)
        cout<<arr[i]<<",";
    int result = maximumToys(arr, n, k);
    cout << "\nMaximum number of toys you can buy: " << result << endl;
    return 0;
}

