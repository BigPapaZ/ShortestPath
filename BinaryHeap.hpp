#ifndef BINARY_HEAP
#define BINARY_HEAP

class BinaryHeap
{
    protected:
        int* heap;
        double* priorities;
        int* positions;
        int numItems;

    public:
        BinaryHeap(const double* priorities, int numItems);
        ~BinaryHeap();

        int getMin() const;
        void popMin();
        bool contains(int item) const;
        //getPriority might me wrong
        double getPriority(int item) const;
        void decreasePriority(int item, double newPriority);

        int percolateUP(int i);
        // void percolateDown(int i);
        void Min_Heapify(int i);

        void swap(int x, int y);

        int getSize() const;
        int getItem(int pos) const;
        int getPos(int item) const;
};

#endif