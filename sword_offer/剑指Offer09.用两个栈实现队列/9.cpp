#include<iostream>
#include<stack>
using namespace std;


class CQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;
    CQueue() {}

    void appendTail(int value) {
        in_stack.push(value);
    }

    int deleteHead() {
        if (!out_stack.empty()) {
            int top = out_stack.top();
            out_stack.pop();
            return top;
        } else {
            while (in_stack.size() > 1) {
                int top = in_stack.top();
                in_stack.pop();
                out_stack.push(top);
            }
            if (in_stack.size() == 1) {
                int top = in_stack.top();
                in_stack.pop();
                return top;
            } else {
                return -1;
            }
        }
    }
};

int main() {
   CQueue* obj = new CQueue();
   obj->appendTail(1);
   cout << obj->deleteHead() << endl;
   cout << obj->deleteHead() << endl;
   return 0;
}
