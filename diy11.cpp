
#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;

        cout << "Stack created." << endl;
    }

    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
        cout << "Stack memory released." << endl;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    return 0;
}
