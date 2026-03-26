#include<iostream>
#include<stack>
using namespace std;

class Stack {
    public:
    // Properties
    int *arr;
    int top;
    int size;

    // Behaviour 
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
void push(int element) {
    if(size - top > 1) {
        top++;
        arr[top] = element;
    }
    else {
        cout << "Stack is Full" << endl;
    }
}
void pop(){
    if(top >= 0) {
        top--;
    }
    else {
        cout << "Stack is empty" << endl;
    }
}
int peek() {
    if(top >= 0) {
        return arr[top];
    }
    else {
        cout << "Stack is empty" << endl;
        return -1;
    }
}
bool isEmpty() {
    if(top == -1){
    return true;
}
else {
    return false;
}

}
};


int main(){
    stack<int> S;

    //creation of stack
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(50);
    S.push(56);

    // deletion of the stack
    S.pop();

    cout << "Top elements are:" << S.top() << endl;
    cout << "Size of the stack is:" << S.size() << endl;

    if(S.empty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
  return 0;
}