#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (pivot >= arr[i])
        {
            cnt++;
        }
    }
    int pivotindex = s + cnt;
    swap(arr[pivotindex], arr[s]);
    int i = s, j = e;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j++]);
        }
    }
    return pivotindex;
}
void Quicksort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    Quicksort(arr, s, p - 1);
    Quicksort(arr, p + 1, e);
}
void selectionsort(int arr[], int n)
{
    int min_pos;
    for (int i = 0; i < n; i++)
    {
        min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_pos] > arr[j])
            {
                min_pos = j;
            }
        }
        if (i != min_pos)
        {
            swap(arr[i], arr[min_pos]);
        }
    }
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void insertionsort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[10] = {10, 9, 8, 6, 9, 3, 4, 5, 8, 1};
    int n = 10;
    insertionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*Quicksort(arr,0,n-1);
     for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
     }
     cout<<endl;*/
}