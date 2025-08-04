#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
  int arr[100];
  int size = 0;

  // Constructor
  heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[parent] < arr[index])
      {
        swap(arr[index], arr[parent]);
        index = parent;
      }
      else
        return;
    }
  }

  void print()
  {
    // will be printed in level order
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deletefromHeap() // O(logn)
  {
    if (size == 0)
    {
      cout << "Nothing to Delete" << endl;
      return;
    }
    
    // Put last element into 1st index
    arr[1] = arr[size];
    // remove last element
    size--;

    // Take root node to its correct pos
    int i = 1;
    while (i < size)
    {
      int left = 2 * i;
      int right = 2 * i + 1;

      if (left < size && arr[i] < arr[left])
      {
        swap(arr[i], arr[left]);
        i = left;
      }
      else if (right < size && arr[i] < arr[right])
      {
        swap(arr[right], arr[i]);
        i = right;
      }
      else
        return;
    }
  }
};

int main()
{
  heap h;
  // insertion Complexity O(logn)
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.print();
  h.deletefromHeap();
  h.print();
}