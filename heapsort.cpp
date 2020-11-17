#include <iostream>

using namespace std;

struct Heap {
    int size = 0;
    int* list;
}heap;

void insert(int k) {
    int i = heap.size;
    heap.list[i] = k;
    heap.size++;
    if (i)
        while (i && heap.list[(i - 1) / 2] > heap.list[i]) {
            swap(heap.list[i], heap.list[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
}

int extract() {
    int k = heap.list[heap.size - 1];
    int ret = heap.list[0];
    heap.list[0] = k;
    heap.list[heap.size - 1] = 0;
    heap.size--;
    int i = 0;
    while ( 2*i+1 <heap.size) {
        if (2 * i + 2 < heap.size) {
            if (heap.list[2 * i + 1] < heap.list[2 * i + 2]) {
                swap(heap.list[i], heap.list[2 * i + 1]);
                i = 2 * i + 1;
            }
            else {
                swap(heap.list[i], heap.list[2 * i + 2]);
                i = 2 * i + 2;
            }
        }
        else if (heap.list[i] > heap.list[2 * i + 1])
        {
            swap(heap.list[i], heap.list[2 * i + 1]);
            i = 2 * i + 1;
        }
        else break;

    }
    return ret;

}

void heapsort(int* v, int n) {
    int i;
    for (i = 0; i < n; i++)
        insert(v[i]);
    for (i = 0; i < n; i++)
        v[i] = extract();

}

int main()
{
   
    heap.list = new int[1001];
    int v[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    heapsort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

}

