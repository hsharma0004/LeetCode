#include <bits/stdc++.h>
using namespace std;

// Heapify is the process of allocating correct position to any node
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // Compare with left child
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    // Compare with right child
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // 1-based indexing
    int n = 5;

    // Building the max heap (bottom-up heapify)
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    // Print the max heap
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
