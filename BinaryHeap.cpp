#include "BinaryHeap.hpp"
#include "iostream"

using namespace std;

BinaryHeap::BinaryHeap(const double* priorites, int numItems)
{
    this->numItems=numItems;

    double* x=new double[numItems];
    this->heap=new int[numItems];
    this->positions=new int[numItems];

    for(int i=0;i<numItems;i++){x[i]=priorites[i];this->heap[i]=i;this->positions[i]=i;}

    this->priorities=x;

    if(numItems-2>=0){for(int i=(numItems-2)/2;i>=0;i--){this->Min_Heapify(i);}}
}

void BinaryHeap::swap(int i, int parent_Index)
{
    this->positions[this->getItem(i)]=parent_Index;
    this->positions[this->getItem(parent_Index)]=i;

    int parent=this->heap[parent_Index];
    this->heap[parent_Index]=this->heap[i];
    this->heap[i]=parent;
}

void BinaryHeap::Min_Heapify(int i)
{
    int left_index=2*i+1;
    int right_index=2*i+2;

    int largest_index;

    if(left_index<this->getSize()&&this->getPriority(this->getItem(left_index))<this->getPriority(this->getItem(i)))
    {largest_index=left_index;}
    else{largest_index=i;}

    if(right_index<this->getSize()&&this->getPriority(this->getItem(right_index))<this->getPriority(this->getItem(largest_index)))
    {largest_index=right_index;}

    if(largest_index!=i)
    {swap(i,largest_index);if(largest_index*2+1<this->getSize()){this->Min_Heapify(largest_index);}}
}

BinaryHeap::~BinaryHeap()
{
    delete[] this->heap;
    delete[] this->priorities;
    delete[] this->positions;
}

int BinaryHeap::getMin() const {return heap[0];}

void BinaryHeap::popMin()
{
    this->swap(0,this->getSize()-1);
    this->numItems--;
    this->Min_Heapify(0);

}

bool BinaryHeap::contains(int item) const {return this->getPos(item)<this->getSize();}

double BinaryHeap::getPriority(int item) const {return this->priorities[item];}

void BinaryHeap::decreasePriority(int item, double newPriority)
{
    this->priorities[item]=newPriority;
    this->percolateUP(this->getPos(item));
}

int BinaryHeap::percolateUP(int i)
{
    if(i!=0)
    {
        int parent_Index=(i-1)/2;
        if(this->getPriority(this->heap[parent_Index])>this->getPriority(this->getItem(i)))
        {
            while(i>0&&this->getPriority(this->heap[parent_Index])>this->getPriority(this->heap[i]))
            {swap(i,parent_Index);i=parent_Index;parent_Index=(i-1)/2;}
            return i;
        }

    }
    return 0;
}

int BinaryHeap::getSize() const {return this->numItems;}

int BinaryHeap::getItem(int pos) const {return this->heap[pos];}

int BinaryHeap::getPos(int item) const {return this->positions[item];}