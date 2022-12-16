// Approach 1 -> TC --> O(N)
// class MyQueue1 {
// private:
//     stack<int> myQueue;
//     stack<int> temp;
// public:
//     MyQueue1() {
//         myQueue = stack<int>();
//         temp = stack<int>();
//     }
    
//     void push(int x) {
//         while(!myQueue.empty()) {
//             temp.push(myQueue.top());
//             myQueue.pop();
//         }
//         myQueue.push(x);
//         while(!temp.empty()) {
//             myQueue.push(temp.top());
//             temp.pop();
//         }
//     }
    
//     int pop() {
//         int ans = myQueue.top();
//         myQueue.pop();
//         return ans;
//     }
    
//     int peek() {
//         return myQueue.top();
//     }
    
//     bool empty() {
//         return myQueue.empty();
//     }
// };

// Approach 2 -> TC --> O(1)
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        input = stack<int>();
        output = stack<int>();
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ans;
        if(!output.empty()) {
            ans = output.top();
            output.pop();
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            ans = output.top();
            output.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans;
        if(!output.empty()) {
            ans = output.top();
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            ans = output.top();
        }
        return ans;
    }
    
    bool empty() {
        if(!output.empty()) return output.empty();
        return input.empty();
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