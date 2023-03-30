#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void swap(int *a,int *b)
{
    int temp = *a;//using pointers
    *a=*b;
    *b = temp;
}

int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x){
            i++;
            swap (&A[i], &A[j]);
        }
    }

    swap (&A[i + 1], &A[r]);

    return (i + 1);
}

void quickSortRecursive(int A[], int p, int r)
{   /*QuickSort recursive implementation*/
    if (p < r){
        int q = partition(A, p,r);
        quickSortRecursive(A, p, q - 1);
        quickSortRecursive(A, q + 1, r);
    }
}

int main()
{
    cout<<"Enter the size of the array below with no spaces, Since time is in MiliSeconds enter a large number"<<endl;
    int Size;
    cin>> Size;

    int arr_rec[Size]={};

    for(int i = 0; i < Size; i++){
        int random=rand() % 10;
        arr_rec[i]=random;
    }

    auto start_time_rec = high_resolution_clock::now();
    quickSortRecursive(arr_rec,0,Size-1);
    auto end_time_rec = high_resolution_clock::now();

    /*for(int i=0;i<Size;i++){
        cout<<arr_rec[i]<<" ";
    }*/
    auto duration_rec = chrono::duration_cast<chrono::milliseconds>(end_time_rec - start_time_rec).count();

    cout << "\nExecution time in Iterative: " << duration_rec<< " MiliSeconds" << endl;
    
    return 0;
}
