#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class stack {
    private:
        int top;
        int Size;
        int *arr; /*pointer to the first element of the creating array*/

    public:
        stack(int stack_size) {
            /*constructor of stack*/
            Size = stack_size;
            arr = new int[Size];
            top = -1; /*index of the top element*/
        }

        bool isEmpty(){
            if (top<0){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if (top==Size-1){
                return true;
            }else{
                return false;
            }
        }

        void push(int value) {
            top++;

            if (top >= Size) {
                cout << "Stack Overflow" << endl;
            } else {
                arr[top] = value;
            }
        }

        int pop(){
            if (isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1; //indicating error
            }else{
                top--;
                return arr[top+1];
            }
        }

        int stackTop(){
            if (isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1; //indicating error
            }else{
                return arr[top];
            }
        }

        void display(){
            /*print the stack*/
            cout<<"[ ";

            for(int i=0; i<top; i++){
                cout<<arr[i]<<", ";
            }
            cout<<arr[top]<<" ]"<<endl;;
        }
};

int main(){
    
    cout<<"Enter the size of the stack : ";
    int Size;
    cin>>Size;
    cout<<endl;
    stack new_stack(Size);
    
    auto start_time= high_resolution_clock::now();

    for(int i=0; i<Size; i++){
        new_stack.push(rand() % 10);
    }
    new_stack.display();

    for(int i=0; i<Size/2; i++){
        new_stack.pop();
    }
    new_stack.display();

    for(int i=0; i< Size/2 - 1; i++){
        new_stack.push(rand() % 10);
    }
    new_stack.display();

    auto end_time= high_resolution_clock::now();
    auto duration_rec = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    cout << "\nExecution time: " << duration_rec<< " MicroSeconds" << endl;
    return 0;

}
