#include <iostream>
using namespace std;
#define MAX 1000

class Stack {
    private : 
        int top;
        int a[MAX];
    public :
        Stack();
        void push(int x);
        void pop();
        void peek();
        void value();
        int size();

};
Stack::Stack() {
    this->top = -1;
}
void Stack::push(int x) {
    if(this->top > MAX -1)
        cout << "Stack is full!!";
    else {
        this->a[++top] = x;
        cout << this->a[top] <<" push into Stack\n";
    }
}
void Stack::pop(){
    if(this->top < 0) 
        cout << "Not have value in Stack";
    else 
        cout << this->a[top--] << "\n";
}
void Stack::peek(){
    if(this->top < 0) 
        cout << "Not have value in Stack";
    else 
        cout << this->a[top] << "\n";
}
void Stack::value(){
    for(int i = 0 ; i <= top ; i++)
        cout << this->a[i] << " ";
    cout << "\n";
}
int Stack::size(){
    return this->top + 1;
}


int main () {
    Stack *stack = new Stack();
    while (1)
    {
        char ch;
        int num;
        cin >> ch;
        
        if(ch == 'X') {
            cout << "End program";
            break;
        }
        else if (ch == 'O') stack->pop();
        else if (ch == 'T') stack->peek();
        else if (ch == 'P') stack->value();
        else if (ch == 'N') cout << stack->size() << "\n";
        else {
            cin >> num;
            stack->push(num);
        }
        
    }
    
}