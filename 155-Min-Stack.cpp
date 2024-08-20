// thi problem can also be done using stack pair but it will take 2n space this takes n space.
// 2*mini-prev_mini=st.top() is the equation used in this

class MinStack {
public:
stack<long long> st;
long long mini=LONG_MAX;
    MinStack() {
      // No need to reinitialize here unless you're doing something specific
     // The member variables are already initialized by the time the constructor runs.
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else if(val<mini){
                st.push(2*(long long)val-mini);
                mini=val;           
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top()<mini){
            mini=2*mini*1LL-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mini)
        return (int)mini;
        else
        return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */