class MyCircularQueue {
public:
    int front;
    int back;
    int siz;
    int capacity ;
    vector<int> arr;
    MyCircularQueue(int k) {
        front =0; 
        back = 0;
        siz = 0;
        vector<int> v(k);
        arr = v;
        capacity = k;
    }
    
    bool enQueue(int val) {
        if(siz == capacity) return false;
        arr[back] = val;
        back++;
        if(back == capacity) back=0;
        siz++;
        return true;
    }
    
    bool deQueue() {
        if(siz == 0)return false;
        front++;
        if(front == capacity) front =0;
        siz--;
        return true;
    }
    
    int Front() {
        if(siz == 0) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(siz == 0) return -1;
        if(back == 0) return arr[capacity-1];
        return arr[back-1];
    }
    
    bool isEmpty() {
        if(siz == 0) return true;
        else return false;
    }
    
    bool isFull() {
        if(siz == capacity ) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */