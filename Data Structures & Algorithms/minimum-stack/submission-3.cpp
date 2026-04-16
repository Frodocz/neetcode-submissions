class MinStack {
    stack<int> st, st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (st2.empty())
        {
            st2.push(val);
        }
        else
        {
            st2.push(min(st2.top(), val));
        }
    }
    
    void pop() {
        if (st.empty()) return;
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
