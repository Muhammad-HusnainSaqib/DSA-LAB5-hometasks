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

    void Push(char x)
    {
        arr[top] = x;
        top++;
    }

    char Pop()
    {
        top--;
        return arr[top];
    }

    bool isEmpty()
    {
        return top == 0;
    }
};


class Queue
{
    char arr[10];
    int front;
    int rear;
    int count;

public:

    Queue()
    {
        front = 0;
        rear = 0;
        count = 0;
    }

    void enqueue(char x)
    {
        arr[rear] = x;
        rear = (rear + 1) % 10;
        count++;
    }

    char dequeue()
    {
        char x = arr[front];

        front = (front + 1) % 10;
        count--;

        return x;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        int index = front;

        for(int i = 0; i < count; i++)
        {
            cout << arr[index] << " ";
            index = (index + 1) % 10;
        }

        cout << endl;
    }
};


void reverseFirstK(Queue &q, int k)
{
    Stack s;

    int n = q.size();

    // Put first K elements into stack
    for(int i = 0; i < k; i++)
    {
        s.Push(q.dequeue());
    }

    // Put them back into queue
    while(!s.isEmpty())
    {
        q.enqueue(s.Pop());
    }

    // Move remaining elements to the back
    for(int i = 0; i < n - k; i++)
    {
        q.enqueue(q.dequeue());
    }
}


int main()
{
    Queue q;

    q.enqueue('J');
    q.enqueue('1');

    q.enqueue('J');
    q.enqueue('2');

    q.enqueue('J');
    q.enqueue('3');

    q.enqueue('J');
    q.enqueue('4');

    q.enqueue('J');
    q.enqueue('5');

    q.enqueue('J');
    q.enqueue('6');

    q.enqueue('J');
    q.enqueue('7');

    cout << "Before: ";
    q.display();

    reverseFirstK(q, 3);

    cout << "After: ";
    q.display();

    return 0;
}
