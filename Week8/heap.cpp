#include <iostream>
using namespace std;

void swap(int*p, int*q){
   //swap using pointers
   int temp = *p;
   *p = *q;
   *q = temp;
}
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2*root +1;
   int right = 2*root +2;
   int largest =root;

   if ((left < n) && (arr[left] > arr[largest])){
       largest = left;
   }

   if ((right < n) && (arr[right] > arr[largest])){
       largest = right;
   }

   if (largest!=root){
      //exchanges root with largest
      swap(&arr[root],&arr[largest]);

      heapify(arr,n,largest);//recursive call
   }
} 

//build max heap
void builMaxHeap(int arr[],int n){
   for(int i =(n-1)/2 ; i>=0 ; i--){
      heapify(arr,n,i);
   }
}
  
   
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   builMaxHeap(arr,n);
  
   // extracting elements from heap one by one
   for(int i= n-1; i>0; i--){

      //exchanges using pointers
      swap(&arr[0],&arr[i]);

      heapify(arr,i,0);
   }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i){
      cout << arr[i] << " ";
   }
   cout << "\n";
}
  
// main program
int main()
{
   int n, count=0, element;

   cout<<"\nEnter the size of the array : ";
   cin>>n;
   int heap_arr[n]={};
   
   cout <<"Enter the space seperated elements of the array"<<endl;
   for (int count=0; count<n ; count++){
      cin>>element;
      heap_arr[count]=element;
   }

   cout<<"\nInput array"<<endl;
   displayArray(heap_arr,n);
  
   cout<<"Max heap array"<<endl;
   builMaxHeap(heap_arr,n);
   displayArray(heap_arr,n);
   
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   cout<<endl;
}