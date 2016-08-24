class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!s1.empty())
        {
            int i=0,size=0;
            size = s1.size();
            while(i<size-1)
            {
                s2.push(s1.top());
                s1.pop();
                i++;
            }
            s1.pop();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else return;
    }

    // Get the front element.
    int peek(void) {
        int ret=0;
        if(!s1.empty())
        {
            int i=0,size=0;
            size = s1.size();
            while(i<size-1)
            {
                s2.push(s1.top());
                s1.pop();
                i++;
            }
            ret = s1.top();
            s2.push(ret);
            s1.pop();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return ret;
        }
        else return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(s1.empty())return true;
        else return false;
    }
private:
    stack<int> s1;
    stack<int> s2;
};