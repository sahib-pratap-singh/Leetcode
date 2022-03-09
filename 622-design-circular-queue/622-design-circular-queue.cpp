class MyCircularQueue {
public:
    vector<int> cqueue;
    int size;
    int front=-1;
    int rear=-1;
    MyCircularQueue(int k) {
        cqueue=vector<int>(k,0);
        size=k;
    }
    
    bool enQueue(int value) {
        if((rear+1)%size==front){
            return false;
        }
        if(front==-1 and rear==-1){
            front=(front+1)%size;
            rear=(rear+1)%size;
        }else
            rear=(rear+1)%size;
        cqueue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(front==-1 and rear==-1){
            return false;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }else
            front=(front+1)%size;
        return true;
    }
    
    int Front() {
        if(front==-1){
            return -1;
        }
        return cqueue[front];
    }
    
    int Rear() {
        if(rear==-1){
            return -1;
        }
        return cqueue[rear];
    }
    
    bool isEmpty() {
        if(front==-1 and rear==-1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((rear+1)%size==front){
            return true;
        }
        return false;
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