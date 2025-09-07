#include <iostream>
using namespace std;

#define MAX_SIZE 10
class Queue{
    public:
    int front;
    int rear;
    int arr[MAX_SIZE];
    Queue(): front(-1), rear(-1) {}
    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX_SIZE - 1; }

    int getFront()
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    void enqueue(int val)
    {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;

        rear++;
        arr[rear] = val;
    }
    int dequeue()
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        front++;
        if (isEmpty())
            front = rear = -1;

        return ans;
    }
    void display()
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue:  ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};