#include <iostream>
using namespace std;

class CircularQueue
{
    int arr[6];
    int front;
    int rear;
    int count;

public:

    CircularQueue()
    {
        front = 0;
        rear = 0;
        count = 0;
    }

    void enqueue(int x)
    {
        if(count == 6)
        {
            cout << "Queue is full" << endl;
            return;
        }

        arr[rear] = x;
        rear = (rear + 1) % 6;
        count++;
    }

    void dequeue()
    {
        if(count == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        front = (front + 1) % 6;
        count--;
    }

    void display()
    {
        int index = front;

        for(int i = 0; i < count; i++)
        {
            cout << arr[index] << " ";
            index = (index + 1) % 6;
        }

        cout << endl;
    }

    void showPositions()
    {
        cout << "Front: " << front << endl;
        cout << "Rear: " << rear << endl;
    }
};

int main()
{
    CircularQueue q;

    // 101 - 106 arrive
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    // First 3 passengers board
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // 107, 108, 109 arrive
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    // Two more passengers board
    q.dequeue();
    q.dequeue();

    // 110 arrives
    q.enqueue(110);

    // One more passenger boards
    q.dequeue();

    // 111, 112 arrive
    q.enqueue(111);
    q.enqueue(112);

    cout << "Final passengers in boarding order: ";
    q.display();

    q.showPositions();

    return 0;
}
