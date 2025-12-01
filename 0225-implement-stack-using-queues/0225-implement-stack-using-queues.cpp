class MyStack {
public:
    queue<int> q;
    queue<int> temp;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while(q.size()>1){
            temp.push(q.front());
            q.pop();
        }
        int ele = q.front();
        q.pop();
        while(temp.size()>0){
            q.push(temp.front());
            temp.pop();
        }
        return ele;
    }
    
    int top() {
        while(q.size()>1){
            temp.push(q.front());
            q.pop();
        }
        int ele = q.front();
        q.pop();
        temp.push(ele);
        
        while(temp.size()>0){
            q.push(temp.front());
            temp.pop();
        }
        return ele;     
    }
    
    bool empty() {
        if(q.size() == 0) return true;
        else return false;
    }
};

/**:"
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */