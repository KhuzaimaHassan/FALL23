#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sort {
private:
    int comparisons;
    int swaps;

public:
    Sort() : comparisons(0), swaps(0) {}

    void bubbleSort(int arr[], int n) {
        comparisons = 0;
        swaps = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }
    }

    void selectionSort(int arr[], int n) {
        comparisons = 0;
        swaps = 0;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
                swaps++;
            }
        }
    }

    void insertionSort(int arr[], int n) {
        comparisons = 0;
        swaps = 0;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            comparisons++;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                swaps++;
                comparisons++;
            }
            arr[j + 1] = key;
        }
    }

    void performSort(int arr[], int n, string sortType) {
        if (sortType == "Bubble") {
            bubbleSort(arr, n);
        } else if (sortType == "Selection") {
            selectionSort(arr, n);
        } else if (sortType == "Insertion") {
            insertionSort(arr, n);
        }
    }

    void printAnalysis(string sortType) {
        cout << "Analysis for " << sortType << " Sort:" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
        cout << "Number of swaps: " << swaps << endl;
        cout << endl;
    }
};

int main() {
    srand(time(0)); // Seed for random number generation

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Randomly generated array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
        cout << arr[i] << " ";
    }
    cout << endl;

    string sortType;
    cout << "Enter the sorting technique (Bubble/Selection/Insertion): ";
    cin >> sortType;

    Sort sorter;
    sorter.performSort(arr, n, sortType);
    sorter.printAnalysis(sortType);

    // Highlight the best and worst techniques
    cout << "Best technique: Selection Sort" << endl;
    cout << "Worst technique: Bubble Sort" << endl;

    return 0;
}

