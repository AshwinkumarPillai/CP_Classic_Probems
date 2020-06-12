// Implement Min heap

class MinHeap
{
    vector<int> heap;

    vector<int> BuildHeap(vector<int> &arr)
    {
        for (int x : arr)
        {
            heap.push_back(x);
        }

        int firstParentIndex = (arr.size() - 2) / 2;
        for (int index = firstParentIndex; i >= 0; i--)
        {
            siftDown(index);
        }
        return heap;
    }

    int peek()
    {
        return heap[0];
    }

    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = heap[i];
    }

    int getParentIndex(int index)
    {
        int parentIndex = (index - 1) / 2;
        if (parentInde < 0)
        {
            return -1;
        }
        return parentIndex;
    }

    int getParent(int parentIndex)
    {
        if (parentIndex == -1)
        {
            return -1;
        }
        return heap[parentIndex];
    }

    int getLeftChildIndex(int parentIndex)
    {
        int l = 2 * parentIndex + 1;
        if (l >= heap.size())
        {
            return -1;
        }
        return l;
    }

    int getLeftChild(int index)
    {
        if (index == -1)
        {
            return -1;
        }
        return heap[index];
    }

    int getRightChildIndex(int parentIndex)
    {
        int r = 2 * parentIndex + 2;
        if (r >= heap.size())
        {
            return -1;
        }
        return r;
    }

    int getRightChild(int index)
    {
        if (index == -1)
        {
            return -1;
        }
        return heap[index];
    }

    void siftDown(int index)
    {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int lc = getLeftChild(leftChildIndex);
        int rc = getRightChild(rightChildIndex);
        if (leftChildIndex != -1 && rightChildIndex != -1)
        {
            int childIndex(lc < rc) ? leftChildIndex : rightChildIndex;
            swap(index, childIndex);
            siftDown(childIndex);
        }
        else if (rightChildIndex != -1)
        {
            swap(index, rightChildIndex);
            siftDown(rightChildIndex);
        }
        else if (leftChildIndex != -1)
        {

            swap(index, leftChildIndex);
            siftDown(leftChildIndex);
        }
    }

    void siftUp(int index)
    {
        int parentIndex = getParentIndex(index);
        while (index > 0 && heap[index] < heap[parentIndex]) //for maxHeap -  heap[index] > heap[parentIndex]
        {
            swap(index, parentIndex);
            index = parentIndex;
            parentIndex = getParentIndex(index);
            if (parentIndex == -1)
                return;
        }
    }

    void insert(int val)
    {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    int remove()
    {
        int val = heap[0];
        swap(0, heap.size() - 1);
        heap.pop_back();
        siftDown(0);
        return val;
    }
};