#include<iostream>
using namespace std;
void insert(int data,int arr[],int &size)
{
    int ind = size;
    arr[ind] = data;
    size++;
    while(ind>0)
    {
        int parent = (ind-1)/2;
        if(arr[parent]<arr[ind])
        {
            swap(arr[ind],arr[parent]);
            ind = parent;
        }
        else{
            return;
        }
    }
}


void maxHeapify(int arr[],int size, int i)
{
    int largest = i;
    int leftIndex = 2*i+1;
    int RightIndex = 2*i+2;
    if(leftIndex<size && arr[leftIndex]>arr[largest])
    {
        largest = leftIndex;
    }
    if(RightIndex<size && arr[RightIndex]>arr[largest])
    {
        largest = RightIndex;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeapify(arr,size,largest);
    }
}

void minHeapify(int arr[],int size, int i)
{
    int smallest = i;
    int leftIndex = 2*i+1;
    int RightIndex = 2*i+2;
    if(leftIndex<size && arr[leftIndex]<arr[smallest])
    {
        smallest = leftIndex;
    }
    if(RightIndex<size && arr[RightIndex]<arr[smallest])
    {
        smallest = RightIndex;
    }
    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        minHeapify(arr,size,smallest);
    }
}


void buildMaxHeap(int arr[],int size)
{
    for(int i = (size-1)/2;i>=0;i--)
    {
        maxHeapify(arr,size,i);
    }
}

void buildMinHeap(int arr[],int size)
{
    for(int i = (size-1)/2;i>=0;i--)
    {
        minHeapify(arr,size,i);
    }
}

void Heapsort(int arr[],int size)
{
    buildMaxHeap(arr,size);
    for(int i =size;i>0;i--)
    {
        swap(arr[0],arr[size-1]);
        size--;
        maxHeapify(arr,size,0);
    }
}

void Printarray(int arr[],int size)
{
    cout<<"Your heap is : \n";
    for(int i =0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int arr[100];
    int size = 0;
    insert(45,arr,size);
    return 0;
}