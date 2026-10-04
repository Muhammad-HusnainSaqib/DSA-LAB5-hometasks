#include <iostream>
using namespace std;
class Stack
{
    char arr[10];
    int top;
public:
    Stack()
    {
        top = 0;
    }
    void push(char x)
    {
        arr[top] = x;
        top++;
    }
    char pop()
    {
        top--;
        return arr[top];
    }
    bool isEmpty()
    {
        return top == 0;
    }
};
class MyQueue
{
    Stack incoming;
    Stack outgoing;
public:
    void enqueue(char x)
    {
        incoming.push(x);
    }
    char dequeue()
    {
        if(outgoing.isEmpty())
        {
            while(!incoming.isEmpty())
            {
                outgoing.push(incoming.pop());
            }
        }
        return outgoing.pop();
    }
};
int main()
{
    MyQueue q;
    q.enqueue('A');
    q.enqueue('B');
    cout << "Dequeue: " << q.dequeue() << endl;
    q.enqueue('C');
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    return 0;
}
