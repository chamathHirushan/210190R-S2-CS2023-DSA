#include <iostream>
#include <chrono>
#include <stack>
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

void quickSortIterative(int arr[], int n) {
    //iterative quickSort function
    if (n <= 1) {return;}
    
    stack<int> s;
    s.push(0);
    s.push(n - 1);
    
    while (!s.empty()) {
        int high = s.top();
        s.pop();
        int low = s.top();
        s.pop();
        
        int pivot_index = partition(arr, low, high);
        
        if (pivot_index - 1 > low) {
            s.push(low);
            s.push(pivot_index - 1);
        }
        
        if (pivot_index + 1 < high) {
            s.push(pivot_index + 1);
            s.push(high);
        }
    }
}

int main()
{
    cout<<"Enter the size of the array below with no spaces, Since time is in MiliSeconds enter a large number"<<endl;
    int Size;
    cin>> Size;

    int arr_itr[Size]={};

    for(int i = 0; i < Size; i++){
        int random=rand() % 10;
        arr_itr[i]=random;
    }

    auto start_time_itr = high_resolution_clock::now();
    quickSortIterative(arr_itr,Size);
    auto end_time_itr = high_resolution_clock::now();

    /*for(int i=0;i<Size;i++){
        cout<<arr_itr[i]<<" ";
    }*/
    auto duration_itr = chrono::duration_cast<chrono::milliseconds>(end_time_itr - start_time_itr).count();

    cout << "\nExecution time in Iterative: " << duration_itr<< " MiliSeconds" << endl;
    
    return 0;
}
