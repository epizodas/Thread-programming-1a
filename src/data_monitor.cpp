#include <iostream>
#include "object.cpp"
using namespace std;

#define MAX_SIZE 10
class DataMonitor {
public:
    int front;
    int rear;
    int count;
    Object arr[MAX_SIZE];
    DataMonitor() : front(0), rear(0), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAX_SIZE; }

    void addItem(const Object& val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = val;
        rear = (rear + 1) % MAX_SIZE;
        count++;
    }

    Object removeItem() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return Object("", 0, 0.0);
        }
        Object ans = arr[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        return ans;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue:  " << endl;
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % MAX_SIZE;
            cout << (i + 1) << ". " << arr[idx].to_string() << endl;
        }
        cout << endl;
    }
};