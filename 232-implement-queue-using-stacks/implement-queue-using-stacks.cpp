/**
FIFO

<- ...... <-  QUEUE

^
.  STACK
.
.

Q:
push
pop
peek
 
1 2 3

push O(1)
pop O(N)
Push s1
pop s2
peek s2

3
2 1
1 2

*/



class MyQueue {
    stack<int> s1,s2;
    int front,rear;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!s1.size())
            front = x;
        s1.push(x);
    }
    
    int pop() {
        if(!s2.size())
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int e=s2.top();
        s2.pop();
        return e;
        
    }
    
    int peek() {
        if (s2.size())
            return s2.top();
        return front;
    }
    
    bool empty() {
        return (!s1.size() && !s2.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */