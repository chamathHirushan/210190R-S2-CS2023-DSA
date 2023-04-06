#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class node{
    public:
        int data; //data of the node
        node* next; //pointer to the next node object

        node(int value){
            data=value;
            next=nullptr; //initial null pointer
        }
};

class stack{
    private:
        node *top; //ponter to the top node

    public:
        stack(){
            top=nullptr; //initial null pointer to top
        }

        bool isEmpty(){
            if (top==nullptr){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            try {
                node* new_node = new node(0);
                delete new_node;
                return false;
            }
            catch (bad_alloc& exception) {
                return true;
            }
        }


        void push(int value){
            try {
                node* new_node= new node(value);
                new_node->next= top;
                top= new_node;
            }
            catch (bad_alloc& exception) {
                cout << "Stack overflow" <<endl;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1; //indicating error
            }

            int popped_data = top->data;
            node* temp = top;
            top = top->next;
            delete temp;

            return popped_data;
        }

        int stackTop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1; //indicating error
            }

            return top->data;
        }

        void display() {
            /*print the stack*/
            cout << "[ ";
            node* temp = top;

            while (temp != nullptr) {
                cout << temp->data << ", ";
                temp = temp->next;
            }

            cout << "\b\b ]" << endl; // overwrites the last ',' and the space
        }
};

int main(){

    stack new_stack = stack();

    cout<<"Enter the size of the stack in order to generate random values: ";
    int Size;
    cin>>Size;
    cout<<endl;
    
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
