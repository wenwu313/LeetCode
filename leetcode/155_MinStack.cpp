class MinStack {  
public:  
    /** initialize your data structure here. */  
    stack<int> stack1;  //数据栈  
    stack<int> stack2;  //存放最小元素的栈  
      
    MinStack() {  
    
    }  
      
    void push(int x) {  
        if(stack2.empty()){  
            stack1.push(x);  
            stack2.push(x);  
        }else{  
            int temp = stack2.top();  
            stack1.push(x);  
            stack2.push(min(x,temp));  
        }  
    }  
      
    void pop() {  
        stack1.pop();  
        stack2.pop();  
    }  
      
    int top() {  
        return stack1.top();  
    }  
      
    int getMin() {  
        return stack2.top();  
    }  
};  
  
/** 
 * Your MinStack object will be instantiated and called as such: 
 * MinStack obj = new MinStack(); 
 * obj.push(x); 
 * obj.pop(); 
 * int param_3 = obj.top(); 
 * int param_4 = obj.getMin(); 
 */  