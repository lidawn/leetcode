class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!q1.empty())q1.push(x);
        else if(!q2.empty())q2.push(x);
        else q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int i = 0,size=0;
       if(q1.empty())
       {
           i=0;
           size = q2.size();
           while(i<size-1)
           {
               q1.push(q2.front());
               q2.pop();
               i++;
           }
           q2.pop();
       }
       else if(q2.empty())
       {
           i=0;
           size = q1.size();
           while(i<size-1)
           {
               q2.push(q1.front());
               q1.pop();
               i++;
           }
           q1.pop();
       }
       else return;
    }

    // Get the top element.
    int top() {
         int i = 0,size=0,ret=0;
       if(q1.empty())
       {
           i=0;
           size = q2.size();
           while(i<size-1)
           {
               q1.push(q2.front());
               q2.pop();
               i++;
           }
           ret = q2.front();
           q1.push(ret);
           q2.pop();
           return ret;
       }
       else if(q2.empty())
       {
           i=0;
           size = q1.size();
           while(i<size-1)
           {
               q2.push(q1.front());
               q1.pop();
               i++;
           }
           ret = q1.front();
           q2.push(ret);
           q1.pop();
           return ret;
       }
       else return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(q1.empty()&&q2.empty())return true;
        else return false;
    }
private:
    queue<int> q1;
    queue<int> q2;
};