#pragma once
using namespace System;
using namespace System::Collections::Generic;

public ref class PriorityQueue
{
private:
    List<IComparable^>^ _elements;

public:
    PriorityQueue()
    {
        _elements = gcnew List<IComparable^>();
    }

    void Push(IComparable^ element)
    {
        _elements->Add(element);
        int i = _elements->Count - 1;
        while (i > 0 && _elements[i]->CompareTo(_elements[Parent(i)]) > 0)
        {
            Swap(i, Parent(i));
            i = Parent(i);
        }
    }

    IComparable^ Pop()
    {
        if (_elements->Count == 0)
        {
            throw gcnew InvalidOperationException("Queue is empty");
        }

        IComparable^ max = _elements[0];
        _elements[0] = _elements[_elements->Count - 1];
        _elements->RemoveAt(_elements->Count - 1);

        HeapifyDown(0);

        return max;
    }

    IComparable^ Peek()
    {
        if (_elements->Count == 0)
        {
            throw gcnew InvalidOperationException("Queue is empty");
        }
        return _elements[0];
    }

    int Count()
    {
        return _elements->Count;
    }

private:
    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    int Left(int i)
    {
        return (2 * i + 1);
    }

    int Right(int i)
    {
        return (2 * i + 2);
    }

    void Swap(int i, int j)
    {
        IComparable^ temp = _elements[i];
        _elements[i] = _elements[j];
        _elements[j] = temp;
    }

    void HeapifyDown(int i)
    {
        int left = Left(i);
        int right = Right(i);
        int largest = i;

        if (left < _elements->Count && _elements[left]->CompareTo(_elements[largest]) > 0)
        {
            largest = left;
        }

        if (right < _elements->Count && _elements[right]->CompareTo(_elements[largest]) > 0)
        {
            largest = right;
        }

        if (largest != i)
        {
            Swap(i, largest);
            HeapifyDown(largest);
        }
    }
};
