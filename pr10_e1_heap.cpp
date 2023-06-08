/*Implement Heap/ Shell Sort algorithm in Java demonstrating data structure with modularity of 
programming Language.*/
#include <iostream>
  using namespace std;
  
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  
  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }
  
  // Driver code
  int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
  
    cout << "Sorted array is \n";
    printArray(arr, n);
  }
/*#include<iostream>
using namespace std;
class hp
{
 int heap[20],heap1[20],x,n1,i;
 public:
 hp()
 { heap[0]=0; heap1[0]=0;
 } 
 void getdata();
 void insert1(int heap[],int);
 void upadjust1(int heap[],int);
 void insert2(int heap1[],int);
 void upadjust2(int heap1[],int);
 void minmax();
};
void hp::getdata()
{ 
 cout<<"\n enter the no. of students";
 cin>>n1;
 cout<<"\n enter the marks";
 for(i=0;i<n1;i++)
 { cin>>x;
 insert1(heap,x);
 insert2(heap1,x);
 }
}
void hp::insert1(int heap[20],int x)
{
 int n;
 n=heap[0]; 
 heap[n+1]=x;
 heap[0]=n+1;
 upadjust1(heap,n+1);
}
void hp::upadjust1(int heap[20],int i)
{
 int temp;
 while(i>1&&heap[i]>heap[i/2])
 {
 temp=heap[i];
 heap[i]=heap[i/2];
 heap[i/2]=temp;
 i=i/2;
 }
}
void hp::insert2(int heap1[20],int x)
{
 int n;
 n=heap1[0]; 
 heap1[n+1]=x;
 heap1[0]=n+1;
 
 upadjust2(heap1,n+1);
}
void hp::upadjust2(int heap1[20],int i)
{
 int temp1;
 while(i>1&&heap1[i]<heap1[i/2])
 {
 temp1=heap1[i];
 heap1[i]=heap1[i/2];
 heap1[i/2]=temp1;
 i=i/2;
 }
}
void hp::minmax()
{
 cout<<"\n max marks"<<heap[1];
 cout<<"\n min marks"<<heap1[1];
 
}
int main()
{ 
 hp h;
 h.getdata();
 h.minmax();
 return 0;
}  */
