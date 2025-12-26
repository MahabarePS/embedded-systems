#include<iostream>
using namespace std;

template <typename T>
class Stack{
    private:
        static const int MAX = 5;
        T arr[MAX];
        int top;
    public:
        Stack(){
            top = -1;
        }
        bool isEmpty() const{
            return top == -1;
        }
        bool isFull() const{
            return top == MAX-1;
        }
        void push(T value){
            if(isFull()){
                cout<<"Stack Overflow! Cannot push.\n";
                return;
            }
            top++;
            arr[top]=value;
            cout<<"Pushed: "<<value <<endl;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow! Cannot pop.\n";
                return;
            }
            // top--;
            // arr[top]=value;
            // cout<<"Popped: "<<value<<endl;
            cout<<"Popped: "<<arr[top]<<endl;
            top--;
        }
        T peek() const{
            if(isEmpty()){
                cout<<"Stack is empty!\n";
                return T();
            }
            return arr[top];
        }
        void displayStack() const{
            if(isEmpty()){
                cout<<"Stack is empty.\n";
                return;
            }
            cout<<"Stack elements (Top to Bottom): ";
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    //Stack of integers
    cout<<"-------Stack of Integers-----"<<endl;
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.displayStack();
    cout<<"Top element: "<<intStack.peek() << endl;
    intStack.pop();
    cout<<"Top element after pop: "<<intStack.peek()<<endl;
    intStack.displayStack();
    cout<<endl;
    return 0;
}