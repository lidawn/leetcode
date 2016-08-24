class MinStack {
public:
    /** initialize your data structure here. */
    
    //两个stack,其中一个存当前最小值
    MinStack() {
        this->s1 = new stack<int>();
        this->s2 = new stack<int>();
    }
    
    void push(int x) {
        this->s1->push(x);
        if(this->s2->empty())this->s2->push(x);
        else if(x <= this->s2->top())this->s2->push(x);
    }
    
    void pop() {
        if(this->s1->empty())return;
        if(this->s1->top() == this->s2->top())
            this->s2->pop();
        this->s1->pop();
    }
    
    int top() {
        //cout<<this->s1->top();
        return this->s1->top();
    }
    
    int getMin() {
        //cout<<this->s1->top();
        //cout<<this->s2->top();
        return this->s2->top();
    }
private:
    stack<int> *s1;
    stack<int> *s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */