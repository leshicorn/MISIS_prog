#include <iostream>
#include <string>

class Heap
{
    static const long long SIZE = 200000; // максимальный размер кучи
    long long *h;         // указатель на массив кучи

    public:
    long long HeapSize; // размер кучи
    Heap();  // конструктор кучи
    void addelem(long long);  // добавление элемента кучи
    void outHeap();  // вывод элементов кучи в форме кучи
    void out();  // вывод элементов кучи в форме массива
    long long getmax();  // удаление вершины (максимального элемента)
    void heapify(long long);  // упорядочение кучи
    ~Heap();  // Деструктор кучи
};

Heap :: Heap()
{
    h = new long long[SIZE];
    HeapSize = 0;
}

Heap :: ~Heap()
{
    delete[] h;
}

void Heap :: addelem(long long n)
{
    long long i = 0, parent = 0;
    i = HeapSize;
    h[i] = n;
    parent = (i - 1) / 2;

    while(parent >= 0 && i > 0)
    {
        if(h[i] > h[parent])
        {
            long long temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

void Heap :: outHeap(void)
{
    long long i = 0;
    long long k = 1;
    while (i < HeapSize)
    {
        while ((i < k) && (i < HeapSize))
        {
            std::cout << h[i] << " ";
            i++;
        }
        std::cout << std::endl;
        k = k * 2 + 1;
    }
}

void Heap :: out(void)
{
    for (long long i = 0; i < HeapSize; i++)
    {
        std::cout << h[i] << " ";
    }
    std::cout << std::endl;
}

void Heap :: heapify(long long i)
{
    long long left = 0, right = 0;
    long long temp = 0;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if(left < HeapSize)
    {
        if(h[i] < h[left])
        {
            temp = h[i];
            h[i] = h[left];
            h[left] = temp;
            heapify(left);
        }
    }

    if(right < HeapSize)
    {
        if(h[i] < h[right])
        {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            heapify(right);
        }
    }
}

long long Heap:: getmax(void)
{
    long long x = h[0];
    x = h[0];
    h[0] = h[HeapSize - 1];

    HeapSize--;
    heapify(0);
    return(x);
}

int main()
{
    Heap heap;
    std::string input = "";

    while (std::cin >> input)
    {
        if (input == "ADD")
        {
            long long n;
            std::cin >> n;
            heap.addelem(n);
        }
        if (input == "EXTRACT")
        {
            if (heap.HeapSize != 0)
                std::cout << heap.getmax() << std::endl;
            else
                std::cout << "CANNOT" << std::endl;
        }
        if (input == "CLEAR")
        {
            while (heap.HeapSize != 0)
            {
                heap.getmax();
            }
        }
    }

    return 0;
}