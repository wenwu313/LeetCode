//两个队列实现一个栈  
class MyStack {  
private:  
    queue<int> que1, que2;  
  
public:  
    /** Initialize your data structure here. */  
    MyStack() {  
  
    }  
  
    /** Push element x onto stack. */  
    void push(int x) {  
        que2.push(x);  
    }  
  
    /** Removes the element on top of the stack and returns that element. */  
    int pop() {  
        if (que2.empty()){  
            int temp = que1.front();  
            que1.pop();  
            while (!que1.empty()){  
                que2.push(temp);  
                temp = que1.front();  
                que1.pop();  
            }  
            return temp;  
        }  
        else{  
            int temp = que2.front();  
            que2.pop();  
            while (!que2.empty()){  
                que1.push(temp);  
                temp = que2.front();  
                que2.pop();  
            }  
            return temp;  
        }  
    }  
  
    /** Get the top element. */  
    int top() {  
        int x = pop();  
        if (!que1.empty())  
            que1.push(x);  
        else  
            que2.push(x);  
        return x;  
    }  
  
    /** Returns whether the stack is empty. */  
    bool empty() {  
        return que1.empty() && que2.empty();  
    }  
};  
/** 
* Your MyStack object will be instantiated and called as such: 
* MyStack obj = new MyStack(); 
* obj.push(x); 
* int param_2 = obj.pop(); 
* int param_3 = obj.top(); 
* bool param_4 = obj.empty(); 
*/  
class MyStack2 {
public:
    queue<int> que1, que2;
    MyStack() {
    }

    void push(int x) {
        if (que1.empty()) {
            que1.push(x);
            while (!que2.empty()) {
                int temp = que2.front();
                que2.pop();
                que1.push(temp);
            }
        }
        else {
            que2.push(x);
            while (!que1.empty()) {
                int temp = que1.front();
                que1.pop();
                que2.push(temp);
            }
        }
    }

    int pop() {
        int x = que1.front();
        if (que1.empty()) {
            x = que2.front();
            que2.pop();
        }
        else
            que1.pop();
        return x;
    }

    int top() {
        return que1.empty() ? que2.front() : que1.front();
    }

    bool empty() {
        return que1.empty() && que2.empty();
    }
};

//一个队列实现一个栈  
class Stack3 {  
public:  
    queue<int> que;  
    void push(int x) {  
        que.push(x);  
        for (int i = 0; i<que.size() - 1; ++i){  
            que.push(que.front());  
            que.pop();  
        }  
    }  
  
    void pop() {  
        que.pop();  
    }  
  
    int top() {  
        return que.front();  
    }  
  
    bool empty() {  
        return que.empty();  
    }  
};  