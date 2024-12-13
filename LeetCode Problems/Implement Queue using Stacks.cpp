// problem link: https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue {
private:
    stack<int> push_stk, pop_stk;
public:
    MyQueue() {
    
    }
    
    void push(int x) {
        push_stk.push(x);
    }
    
    int pop() {
        int pk = this->peek();
        pop_stk.pop();
        return pk;
    }
    
    int peek() {
        if(pop_stk.empty()){
            while(!push_stk.empty()){
                pop_stk.push(push_stk.top());
                push_stk.pop();
            }
        }
        return pop_stk.top();
    }
    
    bool empty() {
        return push_stk.empty() && pop_stk.empty();
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