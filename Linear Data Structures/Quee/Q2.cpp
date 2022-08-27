#include <iostream>
#include <vector>
using namespace std;

struct item
{
    int value;
    int priority;
};

void swap(item *a, item *b)
{
    item temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(vector<item> &heap, int i)
{
    int size = heap.size();

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && heap[l].priority > heap[largest].priority)
        largest = l;
    if (r < size && heap[r].priority > heap[largest].priority)
        largest = r;

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(heap, largest);
    }
}

void insert(vector<item> &heap, item newItem)
{
    int size = heap.size();
    if (size == 0)
    {
        heap.push_back(newItem);
    }
    else
    {
        heap.push_back(newItem);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(heap, i);
        }
    }
}

void printArray(vector<item> &heap)
{
    cout << "\nPrinting elements in heap: \n";
    for (int i = 0; i < heap.size(); ++i)
        cout << "{" << heap[i].value << ", " << heap[i].priority << "}\n";
    cout << "\n";
}

int main()
{
    vector<item> heapArray;

    vector<item> array = {{10, 5}, {20, 15}, {30, 5}, {40, 15}, {50, 10}, {60, 11}, {70, 25}, {80, 10}, {90, 6}, {35, 8}, {45, 16}, {25, 15}, {15, 25}, {65, 15}};

    for (int i = 0; i < array.size(); i++)
    {
        insert(heapArray, array[i]);
    }

    printArray(heapArray);

    return 0;
}