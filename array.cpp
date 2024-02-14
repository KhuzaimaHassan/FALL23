#include <iostream>
using namespace std;

int insertion(int arr[], int k, int l, int m)
{
    for (int j = m + 1; j >= k; j--)
    {
        arr[j + 1] = arr[j];
    }

    arr[k] = l;
    return arr[m];
}
int deletion(int arr[], int delete_, int n)
{
    for (int l = delete_; l < n; l++)
    {
        arr[l] = arr[l + 1];
    }
    return arr[n];
}
int maximum(int arr[], int n)
{
    int max_ = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1] && max_ < arr[i])
        {

            max_ = arr[i];
        }
        else if (max_ < arr[i + 1])
        {
            max_ = arr[i + 1];
        }
    }
    return max_;
}
int minimum(int arr[], int n)
{
    int min_ = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min_ > arr[i + 1])
            min_ = arr[i + 1];
    }
    return min_;
}
int search_(int arr[], int n, int search_element, int count_)
{
    count_ = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search_element)
        {
            count_ += 1;
        }
    }

    return count_;
}
int NUMBERS(int arr[], int n)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            num1 += 1;
        else
            num2 += 1;
        if (arr[i] % 2 == 0)
            num3 += 1;
        else
            num4 += 1;
    }
    cout << "\nNo of Positive numbers: " << num2;
    cout << "\nNo of Negative numbers: " << num1;
    cout << "\nNo of Even numbers: " << num3;
    cout << "\nNo of Odd numbers: " << num4;
    return num1, num2, num3, num4;
}
int selection_sort(int arr[], int n)
{
    int min_pos;
    for (int i = 0; i < n; i++)
    {
        min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_pos])
                min_pos = j;
        }
        if (i != min_pos)
            swap(arr[i], arr[min_pos]);
    }
    return arr[n];
}
int bubble_sort(int arr[], int n)
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
    return arr[n];
}
int insertion_sort(int arr[], int n)
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
    return arr[n];
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
    int insert_index, insert_element;
    cout << "Enter the insert index: ";
    cin >> insert_index;
    cout << "Enter the element to be inserted: ";
    cin >> insert_element;
    insertion(arr, insert_index, insert_element, n);

    for (int k = 0; k < n + 1; k++)
    {
        cout << "Element no " << k + 1 << ": " << arr[k];
        cout << endl;
    }
    int delete_index;
    cout << "Enter the delete index: ";
    cin >> delete_index;
    deletion(arr, delete_index, n);

    for (int k = 0; k < n; k++)
    {
        cout << "Element no " << k + 1 << ": " << arr[k];
        cout << endl;
    }

    cout << "Printing unsorted Array" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << "Element no " << k + 1 << ": " << arr[k];
        cout << endl;
    }
    int max_ = maximum(arr, n);
    cout << endl
         << "Maximum: " << max_ << endl;

    int min_ = minimum(arr, n);
    cout << endl
         << "Minimum: " << min_ << endl;
    int search_element, count_ = 0;
    cout << "Enter the element which you want to search: ";
    cin >> search_element;
    int sear = search_(arr, n, search_element, count_);
    cout << "Element Found: " << sear << " times";
    cout << endl;
    NUMBERS(arr, n);
    cout << endl;
    selection_sort(arr, n);
    cout << endl
         << "Printing Sorted Array using Selection Sort" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << "Element no " << k + 1 << ": " << arr[k];
        cout << endl;
    }
    bubble_sort(arr, n);
    cout << "Printing Sorted Array using Bubble Sort" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << "Element no " << k + 1 << ": " << arr[k];
        cout << endl;
    }

    insertion_sort(arr, n);
    cout << "Printing Sorted Array using Insertion Sort" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << "Element no " << k + 1 << ": " << arr[k];
        cout << endl;
    }

    return 0;
}
